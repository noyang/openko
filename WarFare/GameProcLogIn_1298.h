﻿#pragma once

#if !defined(LOGIN_SCENE_VERSION) || LOGIN_SCENE_VERSION == 1298

#include "GameProcedure.h"

class CGameProcLogIn_1298 : public CGameProcedure
{
public:
	class CUILogIn_1298*		m_pUILogIn;
	
	bool			m_bLogIn; // 로그인 중복 방지..
	std::string		m_szRegistrationSite;

public:
	void	MsgRecv_GameServerGroupList(Packet& pkt);
	void	MsgRecv_AccountLogIn(int iCmd, Packet& pkt);
	int		MsgRecv_VersionCheck(Packet& pkt); // virtual
	int		MsgRecv_GameServerLogIn(Packet& pkt); // virtual - 국가 번호를 리턴한다.
	void	MsgRecv_News(Packet& pkt);

	bool	MsgSend_AccountLogIn(enum e_LogInClassification eLIC);
	bool	MsgSend_NewsReq();

	void Release();
	void Init();
	void Tick();
	void Render();

protected:
	bool ProcessPacket(Packet& pkt) override;

public:

	void ConnectToGameServer(); // 고른 게임 서버에 접속
	CGameProcLogIn_1298();
	~CGameProcLogIn_1298() override;
//	void PacketSend_MGameLogin();
};

class CGameProcLogIn : public CGameProcLogIn_1298 {};

#endif
