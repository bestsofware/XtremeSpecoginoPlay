/*
 * ressourcemanager.h
 */

#ifndef SRC_RESSOURCEMANAGER_H_
#define SRC_RESSOURCEMANAGER_H_

#include "global.h"

#include <SFML/Graphics.hpp>
#include <set>
#include <unordered_map>
#include <string>
#include <memory>

class RessourceManager
{
public:
	enum
	{
		RES_TYPE_TEXTURE,
		RES_TYPE_SOUND,
		RES_TYPE_Count
	};

	static sf::Texture BAD_TEXTURE;
	static const std::string TEXTURES_PATH;

	virtual ~RessourceManager() = 0;

	static void preloadRessources();
	static void clearRessources();

	static void addRessourceToPreload(uint8 resType, const std::string& name);
	static void removeRessourceFromPreload(uint8 resType, const std::string& name);

	static const sf::Texture& getTexture(const std::string& name, bool allowLoading = true);

private:
	static std::set<std::string> s_ressourcesToPreload[RES_TYPE_Count];
	static std::unordered_map<std::string, std::unique_ptr<sf::Texture>> s_loadedTextures;
};

#endif /* SRC_RESSOURCEMANAGER_H_ */
