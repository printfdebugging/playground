#pragma once

#include <SFML/Audio.hpp>

#include <unordered_map>
#include <memory>

template <typename RESOURCE, typename IDENTIFIER = int>
class ResourceManager
{
public:
    ResourceManager(const ResourceManager&)            = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager()                                  = default;

    template <typename... Args>
    void load(const IDENTIFIER& id, Args&&... args);

    RESOURCE& get(const IDENTIFIER& id) const;

private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE>> _map;
};

template <typename RESOURCE, typename IDENTIFIER>
template <typename... Args>
void ResourceManager<RESOURCE, IDENTIFIER>::load(const IDENTIFIER& id, Args&&... args)
{
    std::unique_ptr<RESOURCE> ptr(new RESOURCE);
    if (not ptr->loadFromFile(std::forward<Args>(args)...))
        throw std::runtime_error("[error] impossible to load file");
    _map.emplace(id, std::move(ptr));
}

template <typename RESOURCE, typename IDENTIFIER>
RESOURCE& ResourceManager<RESOURCE, IDENTIFIER>::get(const IDENTIFIER& id) const
{
    return *_map.at(id);
}

/** we used partial specialization for sf::Music because it doesn't use
 * the loadFromFile() function, but instead uses openFromFile(). so the
 * below ResourceManager class is exactly the same as the above one
 * but with RESOURCE = sf::Music and loadFromFile() replaced by
 * openFromFile().
 */
template <typename IDENTIFIER>
class ResourceManager<sf::Music, IDENTIFIER>
{
public:
    ResourceManager(const ResourceManager&)            = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager()                                  = default;

    template <typename... Args>
    void load(const IDENTIFIER& id, Args&&... args);

    sf::Music& get(const IDENTIFIER& id) const;

private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<sf::Music>> _map;
};

template <typename IDENTIFIER>
template <typename... Args>
void ResourceManager<sf::Music, IDENTIFIER>::load(const IDENTIFIER& id, Args&&... args)
{
    std::unique_ptr<sf::Music> ptr(new sf::Music);
    if (not ptr->openFromFile(std::forward<Args>(args)...))
        throw std::runtime_error("[error] impossible to load file");
    _map.emplace(id, std::move(ptr));
}

template <typename IDENTIFIER>
sf::Music& ResourceManager<sf::Music, IDENTIFIER>::get(const IDENTIFIER& id) const
{
    return *_map.at(id);
}
