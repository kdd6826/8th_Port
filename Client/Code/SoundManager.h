#ifndef SoundManager_h__
#define SoundManager_h__
#include "Define.h"


BEGIN(Client)
enum SoundChannel { BGM, PLAYER, PLAYER_EFFECT, MONSTER, EFFECT, MAXCHANNEL };
class SoundManager
{
	DECLARE_SINGLETON(SoundManager)

public:
	static void Destroy();

private:
	SoundManager();
	~SoundManager();

public:
	static void Initialize();
	static void Update();
	static void Release();
public:
//	static void PlaySound(TCHAR* pSoundKey, SoundChannel eID);
	static void PlayOverlapSound(TCHAR* pSoundKey, SoundChannel eID, float offsetVolume = 1.f, float duration = 0.2f);
	static void PlayOverlapSoundWithAmp(TCHAR* pSoundKey, SoundChannel eID);
	static void PlayBGM(TCHAR* pSoundKey);
	static void StopSound(SoundChannel eID);
	static void StopAll();
	static void SetVolume(SoundChannel channel, float per);

private:
	static void LoadSoundFile();

private:
	// ���� ���ҽ� ������ ���� ��ü 
	map<TCHAR*, FMOD_SOUND*> soundMap;
	map<TCHAR*, pair<bool, float>> soundTimeMap;
	// FMOD_CHANNEL : ����ϰ� �ִ� ���带 ������ ��ü 
	FMOD_CHANNEL* channels[MAXCHANNEL];
	// ���� ,ä�� ��ü �� ��ġ�� �����ϴ� ��ü 
	FMOD_SYSTEM* pSystem;
	float volume;
};
END
#endif // CColliderMgr_h__

