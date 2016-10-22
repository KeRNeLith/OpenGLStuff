/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef MODEL_H
#define MODEL_H

#include <memory>

#include "Shaders/shaderprogram.h"

/**
 * @brief The Model class Gère le modèle de données de l'application.
 */
class Model
{
private:
    std::shared_ptr<ShaderProgram> m_program;    ///< Programme shader.

public:
    /**
     * @brief Constructeur initialisant les données nécessaires à l'affichage.
     */
	Model();

    /**
     * @brief update Met à jour le modèle de données (appelé à chaque évènement timer).
     */
	void update();
	
	// Accesseurs
    /**
     * @brief Récupère le programme shader actif.
     * @return Programme shader.
     */
    std::weak_ptr<ShaderProgram> getShaderProgram() const
    {
        return m_program;
    }
};

#endif	// MODEL_H

