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

#ifndef TAXIPATHGRAPH_HPP
#define TAXIPATHGRAPH_HPP

#include <boost/graph/adjacency_list.hpp>

class Player;
struct TaxiNodesEntry;

class TaxiPathGraph
{
public:
    static TaxiPathGraph& Instance()
    {
        static TaxiPathGraph instance;
        return instance;
    }

    void Initialize();
    std::size_t GetCompleteNodeRoute(TaxiNodesEntry const* from, TaxiNodesEntry const* to, Player const* player, std::vector<uint32>& shortestPath);

private:
    struct EdgeCost
    {
        TaxiNodesEntry const* To;
        uint32 Distance;
        uint32 EvaluateDistance(Player const* player) const;
    };
    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::property<boost::vertex_index_t, uint32>, boost::property<boost::edge_weight_t, EdgeCost>> Graph;
    typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;
    typedef Graph::vertex_descriptor vertex_descriptor;
    typedef Graph::edge_descriptor edge_descriptor;
    typedef std::pair<uint32, uint32> edge;

    TaxiPathGraph() { }
    ~TaxiPathGraph() { }

    void AddVerticeAndEdgeFromNodeInfo(TaxiNodesEntry const* from, TaxiNodesEntry const* to, uint32 pathId, std::vector<std::pair<edge, EdgeCost>>& edges);
    vertex_descriptor GetVertexIDFromNodeID(TaxiNodesEntry const* node);
    uint32 GetNodeIDFromVertexID(vertex_descriptor vertexID);
    vertex_descriptor CreateVertexFromFromNodeInfoIfNeeded(TaxiNodesEntry const* node);
    std::size_t GetVertexCount();

    Graph m_graph;
    std::vector<TaxiNodesEntry const*> m_vertices;

    TaxiPathGraph(TaxiPathGraph const&) = delete;
    TaxiPathGraph& operator=(TaxiPathGraph const&) = delete;
};

#define sTaxiPathGraph TaxiPathGraph::Instance()

#endif    /* TAXIPATHGRAPH_HPP */
