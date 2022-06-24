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

#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "GameObject.h"
#include "TransportMgr.h"
#include "VehicleDefines.h"

struct CreatureData;

class Transport : public GameObject, public TransportBase
{
        friend Transport* TransportMgr::CreateTransport(uint32, ObjectGuid::LowType, Map*);

    public:
        Transport();
        ~Transport();

        void CleanupsBeforeDelete(bool finalCleanup = true) override;

        bool CreateTransport(ObjectGuid::LowType guidlow, uint32 entry, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress);
        void Update(uint32 diff) override;

        void BuildUpdate(UpdateDataMapType& data_map) override;

        void AddPassenger(WorldObject* passenger);
        void RemovePassenger(WorldObject* passenger);
        WorldObjectSet& GetPassengers() { return _passengers; }

        Creature* CreateNPCPassenger(ObjectGuid::LowType guid, CreatureData const* data);
        GameObject* CreateGOPassenger(ObjectGuid::LowType guid, GameObjectData const* data);

        /**
        * @fn bool Transport::SummonPassenger(uint64, Position const&, TempSummonType, SummonPropertiesEntry const*, uint32, Unit*, uint32, uint32)
        *
        * @brief Temporarily summons a creature as passenger on this transport.
        *
        * @param entry Id of the creature from creature_template table
        * @param pos Initial position of the creature (transport offsets)
        * @param summonType
        * @param properties
        * @param duration Determines how long the creauture will exist in world depending on @summonType (in milliseconds)
        * @param summoner Summoner of the creature (for AI purposes)
        * @param spellId
        * @param vehId If set, this value overrides vehicle id from creature_template that the creature will use
        *
        * @return Summoned creature.
        */
        TempSummon* SummonPassenger(uint32 entry, Position const& pos, TempSummonType summonType, SummonPropertiesEntry const* properties = nullptr, uint32 duration = 0, Unit* summoner = nullptr, uint32 spellId = 0, uint32 vehId = 0);

        /// This method transforms supplied transport offsets into global coordinates
        void CalculatePassengerPosition(float& x, float& y, float& z, float* o = nullptr) const override
        {
            TransportBase::CalculatePassengerPosition(x, y, z, o, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        }

        /// This method transforms supplied global coordinates into local offsets
        void CalculatePassengerOffset(float& x, float& y, float& z, float* o = nullptr) const override
        {
            TransportBase::CalculatePassengerOffset(x, y, z, o, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        }

        uint32 GetTransportPeriod() const override { return GetUInt32Value(GAMEOBJECT_FIELD_LEVEL); }
        void SetPeriod(uint32 period) { SetUInt32Value(GAMEOBJECT_FIELD_LEVEL, period); }
        uint32 GetTimer() const { return GetGOValue()->Transport.PathProgress; }

        KeyFrameVec const& GetKeyFrames() const { return _transportInfo->keyFrames; }

        void UpdatePosition(float x, float y, float z, float o);

        //! Needed when transport moves from inactive to active grid
        void LoadStaticPassengers();

        //! Needed when transport enters inactive grid
        void UnloadStaticPassengers();

        void EnableMovement(bool enabled);

        void SetDelayedAddModelToMap() { _delayedAddModel = true; }

        TransportTemplate const* GetTransportTemplate() const { return _transportInfo; }
        WorldObjectSet _passengers;
        WorldObjectSet _staticPassengers;
        void UpdatePassengerPositions(WorldObjectSet& passengers);

        uint32 GetPathProgress() const override;

        TimeTrackerSmall _positionChangeTimer;

        bool IsMoving() const override { return _isMoving; }
        void SetMoving(bool val) override { _isMoving = val; }

    private:
        void MoveToNextWaypoint();
        float CalculateSegmentPos(float perc);
        bool TeleportTransport(uint32 newMapid, float x, float y, float z, float o);
        void DoEventIfAny(KeyFrame const& node, bool departure);

        //! Helpers to know if stop frame was reached

        TransportTemplate const* _transportInfo;

        KeyFrameVec::const_iterator _currentFrame;
        KeyFrameVec::const_iterator _nextFrame;
        bool _isMoving;
        bool _pendingStop;

        //! These are needed to properly control events triggering only once for each frame
        bool _triggeredArrivalEvent;
        bool _triggeredDepartureEvent;

        bool _delayedAddModel;
};

class StaticTransport : public Transport
{
    public:
        StaticTransport();
        ~StaticTransport();

        bool Create(ObjectGuid::LowType guidlow, uint32 name_id, Map* map, uint32 phaseMask, Position const& pos, G3D::Quat const& rotation, uint32 animprogress, GOState go_state, uint32 artKit = 0, uint32 aid = 0, GameObjectData const* data = nullptr) override;

        void Update(uint32 diff) override;

        void BuildUpdate(UpdateDataMapType& data_map) override;
        void RelocateToProgress(uint32 progress);
        void UpdatePosition(float x, float y, float z, float o);

        uint32 GetTransportPeriod() const override;

        bool isMapObject;
        bool hasStopFrame;
        uint32 nextStopFrame;
        uint32 FrameUpdateTimer;
        uint32 deltaTimer;
        float moveSpeed;
};

#endif
