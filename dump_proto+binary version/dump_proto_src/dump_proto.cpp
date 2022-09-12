// CONFIG
#define ENABLE_MONSTER_SPECULAR

#ifdef ENABLE_MONSTER_SPECULAR
#include <unordered_map>
#endif


// Find and modify
typedef struct SMobTable
{
	...
	// add this
#ifdef ENABLE_MONSTER_SPECULAR
	float fSpecular;
#endif
} TMobTable;


// Find
bool Set_Proto_Mob_Table(TMobTable* mobTable, cCsvTable& csvTable, std::map<int, const char*>& nameMap)

// Change
#ifdef ENABLE_MONSTER_SPECULAR
bool Set_Proto_Mob_Table(TMobTable* mobTable, cCsvTable& csvTable, std::map<int, const char*>& nameMap, std::unordered_map<int32_t, float>& specularMap)
#else
bool Set_Proto_Mob_Table(TMobTable* mobTable, cCsvTable& csvTable, std::map<int, const char*>& nameMap)
#endif


// In the same function 
// after
	mobTable->fHitRange = static_cast<float>(atof(csvTable.AsStringByIndex(col++)));

// add
#ifdef ENABLE_MONSTER_SPECULAR
	if (specularMap.find(mobTable->dwVnum) != specularMap.end())
		mobTable->fSpecular = specularMap.at(mobTable->dwVnum);
	else
		mobTable->fSpecular = 0.0f;
#endif

// Find
bool BuildMobTable()

// Add after fprintf or wherever
#ifdef ENABLE_MONSTER_SPECULAR
	cCsvTable specularData;
	std::unordered_map<int32_t, float> specularMap;
	if (!specularData.Load("specular_data.txt", '\t'))
	{
		fprintf(stderr, "Failed to read file specular_data.txt \n");
	}
	else
	{
		while (specularData.Next())
		{
			specularMap.emplace(std::make_pair(
				atoi(specularData.AsStringByIndex(0)),
				static_cast<float>(atof(specularData.AsStringByIndex(1)))
			));
		}
	}
#endif

// FIND in the same function(BuildMobTable)
		if (!Set_Proto_Mob_Table(mob_table, data, localMap))
		{
			fprintf(stderr, "Mob prototype table setting failed.\n");
		}

// change it like this

#ifdef ENABLE_MONSTER_SPECULAR
		if (!Set_Proto_Mob_Table(mob_table, data, localMap, specularMap))
#else
		if (!Set_Proto_Mob_Table(mob_table, data, localMap))
#endif
		{
			fprintf(stderr, "Mob prototype table setting failed.\n");
		}

