/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

#include <llapi/LoggerAPI.h>
#include <mc/Mob.hpp>
#include <mc/MoveToBlockGoal.hpp>
#include <mc/BaseMoveToGoal.hpp>
#include <mc/GoHomeGoal.hpp>
#include <mc/BaseMoveToBlockGoal.hpp>
#include <mc/ActorFilterGroup.hpp>
#include <mc/ActorDefinitionTrigger.hpp>
#include <mc/ItemDescriptor.hpp>

#include "version.h"

// We recommend using the global logger.
extern Logger logger;

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *
 */
void PluginInit() {
    // Your code here
}
TInstanceHook(void,
              "??0MoveToBlockGoal@@QEAA@AEAVMob@@MHHHHMVVec3@@MW4TargetSelectionMethod@@V?$"
              "vector@VActorDefinitionTrigger@@V?$allocator@VActorDefinitionTrigger@@@std@@@std@@3V?$"
              "vector@VItemDescriptor@@V?$allocator@VItemDescriptor@@@std@@@5@AEBVActorFilterGroup@@@Z",
              MoveToBlockGoal,
              Mob* mob,
              float startChance,
              int searchRange,
              int searchHeight,
              int tickInterval,
              int stayDuration,
              float goalRadiusSq,
              void* a9,
              int a10,
              enum class TargetSelectionMethod targetSelectionMethod,
              void* a12,
              void* a13,
              class ItemDescriptor** a14,
              class FilterGroup* a15) {
    // logger.info("MoveToBlockGoal {} {} {} {} {} {}", mob->getTypeName(), searchRange, searchHeight, tickInterval,
    // stayDuration, (int)TargetSelectionMethod);
    if (mob->getTypeName() == "minecraft:bee") {
        targetSelectionMethod = TargetSelectionMethod::Nearest;
    }
    original(this, mob, startChance, searchRange, searchHeight, tickInterval, stayDuration, goalRadiusSq, a9, a10,
             targetSelectionMethod, a12, a13, a14, a15);
}