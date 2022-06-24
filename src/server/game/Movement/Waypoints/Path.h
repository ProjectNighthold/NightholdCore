/*
 *###############################################################################
 *#                                                                             #
 *# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
 *#                                                                             #
 *# This file is free software; as a special exception the author gives         #
 *# unlimited permission to copy and/or distribute it, with or without          #
 *# modifications, as long as this notice is preserved.                         #
 *#                                                                             #
 *# This program is distributed in the hope that it will be useful, but         #
 *# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
 *# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
 *#                                                                             #
 *# Read the THANKS file on the source root directory for more info.            #
 *#                                                                             #
 *###############################################################################
 */

#ifndef TRINITYCORE_PATH_H
#define TRINITYCORE_PATH_H

#include "Common.h"
#include <deque>

struct PathNode
{
    PathNode(): x(0.0f), y(0.0f), z(0.0f) { }
    PathNode(float _x, float _y, float _z): x(_x), y(_y), z(_z) { }
    float x, y, z;
};
template<typename PathElem, typename PathNode = PathElem>

class Path
{
    public:
        size_t size() const { return i_nodes.size(); }
        bool empty() const { return i_nodes.empty(); }
        void resize(uint32 sz) { i_nodes.resize(sz); }
        void clear() { i_nodes.clear(); }
        void erase(uint32 idx) { i_nodes.erase(i_nodes.begin()+idx); }
        void crop(uint32 start, uint32 end)
        {
            while(start && !i_nodes.empty())
            {
                i_nodes.pop_front();
                --start;
            }

            while(end && !i_nodes.empty())
            {
                i_nodes.pop_back();
                --end;
            }
        }

        float GetTotalLength(uint32 start, uint32 end) const
        {
            float len = 0.0f;
            for (uint32 idx=start+1; idx < end; ++idx)
            {
                PathNode const& node = i_nodes[idx];
                PathNode const& prev = i_nodes[idx-1];
                float xd = node.x - prev.x;
                float yd = node.y - prev.y;
                float zd = node.z - prev.z;
                len += sqrtf(xd*xd + yd*yd + zd*zd);
            }
            return len;
        }

        float GetTotalLength() const { return GetTotalLength(0, size()); }

        float GetPassedLength(uint32 curnode, float x, float y, float z) const
        {
            float len = GetTotalLength(0, curnode);

            if (curnode > 0)
            {
                PathNode const& node = i_nodes[curnode-1];
                float xd = x - node.x;
                float yd = y - node.y;
                float zd = z - node.z;
                len += sqrtf(xd*xd + yd*yd + zd*zd);
            }

            return len;
        }

        PathNode& operator[](size_t idx) { return i_nodes[idx]; }
        PathNode const& operator[](size_t idx) const { return i_nodes[idx]; }

        void set(size_t idx, PathElem elem) { i_nodes[idx] = elem; }

    protected:
        std::deque<PathElem> i_nodes;
};

typedef Path<PathNode> SimplePath;

#endif

