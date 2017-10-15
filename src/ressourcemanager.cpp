/*
 * ressourcemanager.cpp
 */

#include "ressourcemanager.h"

sf::Texture RessourceManager::BAD_TEXTURE;
const std::string RessourceManager::TEXTURES_PATH = "data/img/";

void RessourceManager::preloadRessources()
{
	std::string path;

	for(uint8 type = 0; type < RES_TYPE_Count; type++)
	{
		for(auto& name : s_ressourcesToPreload[type])
		{
			if(type == RES_TYPE_TEXTURE)
			{
				getTexture(name, true);
			}
		}
	}
}

void RessourceManager::clearRessources()
{
	s_loadedTextures.clear();
}

void RessourceManager::addRessourceToPreload(uint8 resType,
		const std::string& name)
{
	if(resType >= RES_TYPE_Count)
		return;

	s_ressourcesToPreload[resType].insert(name);
}

void RessourceManager::removeRessourceFromPreload(uint8 resType,
		const std::string& name)
{
	if(resType >= RES_TYPE_Count)
		return;

	s_ressourcesToPreload[resType].erase(name);
}

const sf::Texture& RessourceManager::getTexture(const std::string& name,
		bool allowLoading)
{
	auto it = s_loadedTextures.find(name);

	if(it == s_loadedTextures.end())
	{
		if(!allowLoading)
			return BAD_TEXTURE;

		std::unique_ptr<sf::Texture> ptr(new sf::Texture());

		std::string path = TEXTURES_PATH + name;

		if(!ptr->loadFromFile(path))
		{
#ifdef DEBUG
			dbg() << "Could not load texture ressource \"" << path << "\"";
#endif
			return BAD_TEXTURE;
		}

		const sf::Texture& ret = *ptr.get();
		s_loadedTextures[name] = std::move(ptr);

		return ret;
	}

	return *(it->second.get());
}

std::set<std::string> RessourceManager::s_ressourcesToPreload[RES_TYPE_Count];
std::unordered_map<std::string, std::unique_ptr<sf::Texture>> RessourceManager::s_loadedTextures;
