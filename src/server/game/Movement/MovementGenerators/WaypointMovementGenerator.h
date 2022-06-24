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

#ifndef TRINITY_WAYPOINTMOVEMENTGENERATOR_H
#define TRINITY_WAYPOINTMOVEMENTGENERATOR_H

/** @page PathMovementGenerator is used to generate movements
 * of waypoints and flight paths.  Each serves the purpose
 * of generate activities so that it generates updated
 * packets for the players.
 */

#include "MovementGenerator.h"
#include "Player.h"
#include "WaypointManager.h"

#define FLIGHT_TRAVEL_UPDATE  100
#define STOP_TIME  1 * IN_MILLISECONDS
#define TIMEDIFF_NEXT_WP      250

template<class T, class P>
class PathMovementBase
{
    public:
        PathMovementBase() : i_path(), i_currentNode(0) { }
        virtual ~PathMovementBase() { };

        uint32 GetCurrentNode() const { return i_currentNode; }

    protected:
        P i_path;
        uint32 i_currentNode;
};

template<class T>
class WaypointMovementGenerator;

template<>
class WaypointMovementGenerator<Creature> : public MovementGeneratorMedium< Creature, WaypointMovementGenerator<Creature> >,
    public PathMovementBase<Creature, WaypointPath const*>
{
    public:
        WaypointMovementGenerator(uint32 _path_id = 0, bool _repeating = true, float _randomMoveX = 0, float _randomMoveY = 0, bool _forceTPToStart = false)
            : i_nextMoveTime(0), m_isArrivalDone(false), path_id(_path_id), repeating(_repeating), goBack(false), randomMoveX(_randomMoveX), randomMoveY(_randomMoveY), forceTPToStart(_forceTPToStart)  { }
        ~WaypointMovementGenerator() { i_path = nullptr; }
        void DoInitialize(Creature &);
        void DoFinalize(Creature &);
        void DoReset(Creature &);
        bool DoUpdate(Creature &, const uint32 &diff);

        void MovementInform(Creature &);

        MovementGeneratorType GetMovementGeneratorType() override { return WAYPOINT_MOTION_TYPE; }

        // now path movement implmementation
        void LoadPath(Creature &c);

        bool GetResetPos(Creature&, float& x, float& y, float& z);

    private:

        void Stop(int32 time) { i_nextMoveTime.Reset(time);}

        bool Stopped() { return !i_nextMoveTime.Passed();}

        bool CanMove(int32 diff)
        {
            i_nextMoveTime.Update(diff);
            return i_nextMoveTime.Passed();
        }

        void OnArrived(Creature&);
        bool StartMove(Creature&);

        void StartMoveNow(Creature& creature)
        {
            i_nextMoveTime.Reset(0);
            StartMove(creature);
        }

        TimeTrackerSmall i_nextMoveTime;
        bool m_isArrivalDone;
        uint32 path_id;
        bool repeating;
        bool goBack;
        float randomMoveX;
        float randomMoveY;
        bool forceTPToStart;
};

template<>
class WaypointMovementGenerator<Player> : public MovementGeneratorMedium< Player, WaypointMovementGenerator<Player> >,
    public PathMovementBase<Player, WaypointPath const*>
{
    public:
        WaypointMovementGenerator(uint32 _path_id = 0)
            : i_nextMoveTime(0), m_isArrivalDone(false), path_id(_path_id)  { }
        ~WaypointMovementGenerator() { i_path = nullptr; }

        void LoadPath(Player &p);
        void DoInitialize(Player &);
        void DoFinalize(Player &);
        void DoReset(Player &);
        bool DoUpdate(Player &, const uint32 &diff);
        MovementGeneratorType GetMovementGeneratorType() override { return WAYPOINT_MOTION_TYPE; }

    private:

        bool StartMove(Player&);
        void Stop(int32 time) { i_nextMoveTime.Reset(time);}
        bool Stopped() { return !i_nextMoveTime.Passed();}
        void OnArrived(Player&);

        bool CanMove(int32 diff)
        {
            i_nextMoveTime.Update(diff);
            return i_nextMoveTime.Passed();
        }

        void StartMoveNow(Player& player)
        {
            i_nextMoveTime.Reset(0);
            StartMove(player);
        }

        TimeTrackerSmall i_nextMoveTime;
        bool m_isArrivalDone;
        uint32 path_id;
};

/** FlightPathMovementGenerator generates movement of the player for the paths
 * and hence generates ground and activities for the player.
 */
class FlightPathMovementGenerator : public MovementGeneratorMedium< Player, FlightPathMovementGenerator >,
    public PathMovementBase<Player, TaxiPathNodeList>
{
    public:
        explicit FlightPathMovementGenerator()
        {
            i_currentNode = 0;
            _endGridX = 0.0f;
            _endGridY = 0.0f;
            _endGridZ = 0.0f;
            _endMapId = 0;
            _preloadTargetNode = 0;
        }
        void LoadPath(Player& player, uint32 startNode = 0);
        void DoInitialize(Player& );
        void DoReset(Player& );
        void DoFinalize(Player& );
        bool DoUpdate(Player& , const uint32&);
        MovementGeneratorType GetMovementGeneratorType() override { return FLIGHT_MOTION_TYPE; }

        TaxiPathNodeList const& GetPath() { return i_path; }
        uint32 GetPathAtMapEnd() const;
        bool HasArrived() const { return (i_currentNode >= i_path.size()); }
        void SetCurrentNodeAfterTeleport();
        void SkipCurrentNode() { ++i_currentNode; }
        void DoEventIfAny(Player& player, TaxiPathNodeEntry const& node, bool departure);

        bool GetResetPos(Player&, float& x, float& y, float& z);

        void InitEndGridInfo();
        void PreloadEndGrid();

    private:

        float _endGridX;                            //! X coord of last node location
        float _endGridY;                            //! Y coord of last node location
        float _endGridZ;                            //! Z coord of last node location
        uint32 _endMapId;                           //! map Id of last node location
        uint32 _preloadTargetNode;                  //! node index where preloading starts

        struct TaxiNodeChangeInfo
        {
            uint32 PathIndex;
            int32 Cost;
        };

        std::deque<TaxiNodeChangeInfo> _pointsForPathSwitch;    //! node indexes and costs where TaxiPath changes
};

#endif
