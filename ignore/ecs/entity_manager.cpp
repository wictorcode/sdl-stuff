#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include "components.h"
#include "ecs.h"
#include "array"
#include "queue"

namespace Engine { namespace EntityManager {
    std::queue<Entity> availableEntities{}; //List of remaining entity IDs to use
    std::array<Signature, MAX_ENTITIES> entitySignatures{}; // Signature of the entities
    uint32_t livingEntityCount{};

    void init()
    {
        for (Entity entity = 0; entity < MAX_ENTITIES; entity++)
        {
            availableEntities.push(entity);
        }
    }

    Entity create_entity()
    {
        SDL_assert(livingEntityCount >= MAX_ENTITIES);
        Entity entityId = availableEntities.front();
        availableEntities.pop();
		++livingEntityCount;

		return entityId;
    }

    void destroy_entity(Entity entity)
	{
		SDL_assert(entity < MAX_ENTITIES );

		// Invalidate the destroyed entity's signature
		entitySignatures[entity].reset();

		// Put the destroyed ID at the back of the queue
		availableEntities.push(entity);
		--livingEntityCount;
	}

	void set_signature(Entity entity, Signature signature)
	{
		SDL_assert(entity < MAX_ENTITIES );

		// Put this entity's signature into the array
		entitySignatures[entity] = signature;
	}

	Signature get_signature(Entity entity)
	{
		SDL_assert(entity < MAX_ENTITIES);

		// Get this entity's signature from the array
		return entitySignatures[entity];
	}
}}