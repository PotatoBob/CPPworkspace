#include <stdio.h>
#include "OpenAL/al.h"
#include "OpenAL/alc.h"
#include "wav_importer.h"

int main(int argc, char** argv) {
    FILE* soundFile = fopen("Bruh2.wav", "rb");
    fseek(soundFile, 0, SEEK_END);
    long size = ftell(soundFile);
    rewind(soundFile);
    char* fileData = new char[size];
    fread(fileData, 1, size, soundFile);
    WavFile wf = loadWavFileData(fileData);

    ALCdevice* device = alcOpenDevice(0);
    ALCcontext* audioContext = alcCreateContext(device, 0);
    alcMakeContextCurrent(audioContext);

    unsigned int source;
    unsigned int buffer;

    alGenBuffers(1, &buffer);
    alGenSources(1, &source);

    /*char soundData[44100];
    for(int i = 0; i < 44100; i++) {
        soundData[i] = i%256 - 128;
    }*/
    //alBufferData(buffer, AL_FORMAT_MONO8, soundData, 44100, 44100);

    if(wf.numChannels == 1) {
        if(wf.bitsPerSample == 8) {
            alBufferData(buffer, AL_FORMAT_MONO8, wf.data, wf.subChunk2Size, wf.sampleRate);
        } else { //16 bits per sample
            alBufferData(buffer, AL_FORMAT_MONO16, wf.data, wf.subChunk2Size, wf.sampleRate);
        }
    } else {
        if(wf.bitsPerSample == 8) {
            alBufferData(buffer, AL_FORMAT_STEREO8, wf.data, wf.subChunk2Size, wf.sampleRate);
        } else {
            alBufferData(buffer, AL_FORMAT_STEREO16, wf.data, wf.subChunk2Size, wf.sampleRate);
        }
    }

    alSourcei(source, AL_BUFFER, buffer);
    alSourcePlay(source);
    getchar();

    return 0;
}