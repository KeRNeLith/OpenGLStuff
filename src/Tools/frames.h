/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef FRAMESDATA_H
#define FRAMESDATA_H

/**
 * @brief The FramesData struct Utilitaire de calcul des frames par seconde et pour le timer.
 */
struct FramesData
{
    static unsigned int m_nbSeconds;			///< Compteur de secondes depuis le lancement de l'application.
    static unsigned int m_nbFrames;            	///< Nombre courant de frames.
    static unsigned int m_lastNbFrames; 		///< Compteur de frames passées.
    static unsigned int m_nextDueFrameDate; 	///< Pour timer affichage.
    static unsigned int m_fps; 					///< Frames par secondes (FPS).

private: 
    static char m_fpsDescriptor[200];   ///< Chaine de caractère descriptive du FrameData.

public:
    /**
     * @brief init Initialise la description des FPS.
     */
	static void init();

	/**
     * @brief Met à jour l'information du Frame Rate
     * @return True si une mise à jour a eu lieu (chaque seconde).
	 */
	static bool update();

	/**
     * @return Description des frame : numéro de frame, durée, et FPS
	 */
	static const char* getFPSDescriptor()
	{
		return m_fpsDescriptor;
	}
};

#endif  // FRAMESDATA_H


