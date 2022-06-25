SET @dbname = "legion_hotfixes";
SET @tablename = "garr_mission";
SET @columnname = "RelationshipData";
SET @preparedStatement = (SELECT IF(
  (
    SELECT COUNT(*) FROM INFORMATION_SCHEMA.COLUMNS
    WHERE
      (table_name = @tablename)
      AND (table_schema = @dbname)
      AND (column_name = @columnname)
  ) > 0,
  "SELECT 1",
  CONCAT("ALTER TABLE ", @tablename, " CHANGE COLUMN ", "CriteriaID", " `RelationshipData` INT(11) NOT NULL DEFAULT '0' AFTER `EnvGarrMechanicID`;")
));
PREPARE alterIfNotExists FROM @preparedStatement;
EXECUTE alterIfNotExists;
DEALLOCATE PREPARE alterIfNotExists;
