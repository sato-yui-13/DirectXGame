//#include "Sound.h"
//
//unsigned long chunkSize; // 使われていない場合
//
//
//// 初期化
//// 初期化関数
//bool Sound::InitDirectSound(HWND hwnd) {
//
//	 
//	
//	if (FAILED(DirectSoundCreate8(NULL, &pDirectSound, NULL))) {
//		return false;
//	}
//	if (FAILED(pDirectSound->SetCooperativeLevel(hwnd, DSSCL_PRIORITY))) {
//		return false;
//	}
//
//	// プライマリバッファを作成
//	DSBUFFERDESC bufferDesc;
//	ZeroMemory(&bufferDesc, sizeof(DSBUFFERDESC));
//	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
//	bufferDesc.dwFlags = DSBCAPS_PRIMARYBUFFER;
//	bufferDesc.dwBufferBytes = 0;
//	bufferDesc.lpwfxFormat = NULL;
//
//	if (FAILED(pDirectSound->CreateSoundBuffer(&bufferDesc, &pPrimaryBuffer, NULL))) {
//		return false;
//	}
//
//	// フォーマット設定
//	WAVEFORMATEX waveFormat;
//	ZeroMemory(&waveFormat, sizeof(WAVEFORMATEX));
//	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
//	waveFormat.nSamplesPerSec = 44100;
//	waveFormat.wBitsPerSample = 16;
//	waveFormat.nChannels = 2;
//	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
//	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
//
//	if (FAILED(pPrimaryBuffer->SetFormat(&waveFormat))) {
//		return false;
//	}
//
//	return true;
//}
//
//// WAVファイルの読み込み
//bool Sound::LoadWaveFile(const char* filename, IDirectSoundBuffer8** buffer) {
//	FILE* filePtr;
//	WaveHeaderType waveFileHeader;
//	WAVEFORMATEX waveFormat;
//	DSBUFFERDESC bufferDesc;
//	IDirectSoundBuffer* tempBuffer;
//	unsigned char* waveData;
//	unsigned char* bufferPtr;
//	unsigned long bufferSize;
//
//	if (fopen_s(&filePtr, filename, "rb") != 0) {
//		std::cerr << "Error: Unable to open the file " << filename << std::endl;
//    
//		return false;
//	}
//
//	fread(&waveFileHeader, sizeof(WaveHeaderType), 1, filePtr);
//
//	// WAVフォーマットの検証
//	if ((waveFileHeader.format[0] != 'W') || (waveFileHeader.format[1] != 'A') || (waveFileHeader.format[2] != 'V') || (waveFileHeader.format[3] != 'E')) {
//		std::cerr << "Error: Invalid WAV format in file " << filename << std::endl;
//		fclose(filePtr);
//		return false;
//	}
//
//	// フォーマットの設定
//	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
//	waveFormat.nSamplesPerSec = waveFileHeader.sampleRate;
//	waveFormat.wBitsPerSample = waveFileHeader.bitsPerSample;
//	waveFormat.nChannels = waveFileHeader.numChannels;
//	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
//	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
//	waveFormat.cbSize = 0;
//
//	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
//	bufferDesc.dwFlags = DSBCAPS_CTRLVOLUME;
//	bufferDesc.dwBufferBytes = waveFileHeader.dataSize;
//	bufferDesc.lpwfxFormat = &waveFormat;
//
//	// セカンダリーバッファの作成
//	if (FAILED(pDirectSound->CreateSoundBuffer(&bufferDesc, &tempBuffer, NULL))) {
//		fclose(filePtr);
//		return false;
//	}
//
//	if (FAILED(tempBuffer->QueryInterface(IID_IDirectSoundBuffer8, (void**)&*buffer))) {
//		tempBuffer->Release();
//		fclose(filePtr);
//		return false;
//	}
//
//	tempBuffer->Release();
//	tempBuffer = NULL;
//
//	// 音声データをメモリにロード
//	fseek(filePtr, sizeof(WaveHeaderType), SEEK_SET);
//	waveData = new unsigned char[waveFileHeader.dataSize];
//	fread(waveData, 1, waveFileHeader.dataSize, filePtr);
//	fclose(filePtr);
//
//	(*buffer)->Lock(0, waveFileHeader.dataSize, (void**)&bufferPtr, (DWORD*)&bufferSize, NULL, 0, 0);
//	memcpy(bufferPtr, waveData, waveFileHeader.dataSize);
//	(*buffer)->Unlock((void*)bufferPtr, bufferSize, NULL, 0);
//
//	// ここで pSecondaryBuffer に tempBuffer を設定
//	pSecondaryBuffer = *buffer; // セカンダリバッファの設定
//	tempBuffer->Release();
//	tempBuffer = nullptr;
//	delete[] waveData;
//	return true;
//}
//
//
//// WAVファイルの再生
//void Sound::PlayWaveFile() {
//	if (pSecondaryBuffer == nullptr) {
//		std::cerr << "Error: pSecondaryBuffer is not initialized." << std::endl;
//		return;
//	}
//	if (pDirectSound == nullptr) {
//		std::cerr << "Error: DirectSound is not initialized." << std::endl;
//		return;
//	}
//
//	pSecondaryBuffer->SetCurrentPosition(0);
//	pSecondaryBuffer->SetVolume(DSBVOLUME_MAX);
//	pSecondaryBuffer->Play(0, 0, 0);
//}