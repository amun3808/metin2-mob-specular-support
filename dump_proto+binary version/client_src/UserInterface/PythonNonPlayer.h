// Find
typedef struct SMobTable
{
	...
	// and add here(wherever you want, it doesn't have to be at the end)
#ifdef ENABLE_MONSTER_SPECULAR
	float fSpecular;
#endif
} TMobTable;


// find
// 		DWORD				GetMonsterColor(DWORD dwVnum);

// add after
#ifdef ENABLE_MONSTER_SPECULAR
		float				GetMonsterSpecular(DWORD dwVnum);
#endif