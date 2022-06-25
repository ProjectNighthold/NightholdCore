/* fix quest https://es.wowhead.com/quest=13886/v%C3%B3rtice */
/* https://es.wowhead.com/npc=34295/lord-magmathar */
UPDATE creature_template SET unit_flags2=0 WHERE entry=34295;