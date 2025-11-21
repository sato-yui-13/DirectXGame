//#pragma once
//#include <dsound.h>
//#include <cstdio>
//#include <iostream>
// // DirectSoundの関数を使うためにインクルード
//
//// msgはexternで宣言する
//extern struct tagMSG msg; // 実体は別のcppファイルで定義
//
//class Sound {
//public:
//	bool InitDirectSound(HWND hwnd);
//	bool LoadWaveFile(const char* filename, IDirectSoundBuffer8** buffer);
//	
//	void PlayWaveFile();
//	void Play() {
//		PlayWaveFile(); // PlayWaveFile を呼び出してサウンドを再生
//	}
//
//	private:
//	//bgmのファイル
//	IDirectSoundBuffer8* soundBuffer = nullptr;
//	
//
//	
//IDirectSound8* pDirectSound;
//	IDirectSoundBuffer* pPrimaryBuffer;
//	IDirectSoundBuffer* pSecondaryBuffer;
//
//
//	struct WaveHeaderType {
//		char chunkId[4]; // "RIFF"
//		unsigned long chunkSize;
//		char format[4]; // "WAVE"
//
//		char subChunkId[4]; // "fmt "
//		unsigned long subChunkSize;
//		unsigned short audioFormat;
//		unsigned short numChannels;
//		unsigned long sampleRate;
//		unsigned long byteRate;
//		unsigned short blockAlign;
//		unsigned short bitsPerSample;
//
//		char dataChunkId[4]; // "data"
//		unsigned long dataSize;
//	};
//};
