// Find
void CInstanceBase::SetShape(DWORD eShape, float fSpecular)
{
	if (IsPoly())
	{
		m_GraphicThingInstance.SetShape(0);	
	}
	else
	{
		m_GraphicThingInstance.SetShape(eShape, fSpecular);		
	}

	m_eShape = eShape;
}

// Change it like this:
void CInstanceBase::SetShape(DWORD eShape, float fSpecular)
{
	if (IsPoly())
	{
		m_GraphicThingInstance.SetShape(0);	
	}
	else
	{
#ifdef ENABLE_MONSTER_SPECULAR
		if(!IsPC() && !fSpecular)
			fSpecular = CPythonNonPlayer::Instance().GetMonsterSpecular(m_dwRace);
#endif
		m_GraphicThingInstance.SetShape(eShape, fSpecular);		
	}

	m_eShape = eShape;
}