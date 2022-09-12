// Find
// DWORD CPythonNonPlayer::GetMonsterColor(DWORD dwVnum)

// Add after
#ifdef ENABLE_MONSTER_SPECULAR
float CPythonNonPlayer::GetMonsterSpecular(DWORD dwVnum)
{
	const TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
		return 0.0f;

	return c_pTable->fSpecular;
}
#endif