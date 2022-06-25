/* cambio de phase zona de misiones y ruta de vuelo draenor */
UPDATE `creature` SET `PhaseId` = 0 WHERE `zoneId` = 6721;
UPDATE `gameobject` SET `PhaseId` = 0 WHERE `zoneId` = 6721;
