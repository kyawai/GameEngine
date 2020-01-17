#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "openAL/AL/al.h"
#include "openAL/AL/alc.h"
#include "Component.h"
#include <vector>

/**
*Creates and plays the background music inside the program
*/
class Audio : public Component

{
		ALuint id = 0; ///< Create the audio ID
		ALenum format = 0; ///< Create the format
		ALsizei freq = 0; ///< Create the frequency
		std::vector<char> bufferData; ///< Create a vector of characters 
		ALuint sid = 0; ///< Create state ID
		ALint state = 0; ///< Create state

public:
		/**
		* \brief Audio constructor
		*/
		Audio();
		/**
		* \brief Audio destructor
		*/
		~Audio();
		/**
		* \brief Start of the file when called. Initialises the buffers and loads the audio
		*/
		void AudioInit(char* _audio);
		/**
		* \brief Plays the audio in set position in set buffer
		*/
		void PlayAudio();
		/**
		* \brief Function to load the audio
		*/
		void LoadAudio(char* _audio);
		/**
		* \brief Check if the audio is playing
		*/
		bool CheckPlaying();
		/**
		* \brief Check every tick if the background music is playing. If it isnt repeat it
		*/
		void onTick();
};


#endif
