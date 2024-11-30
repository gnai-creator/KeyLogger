#include "logger.h"
struct OurEventSink : public RE::BSTEventSink<RE::TESHitEvent> {
    RE::BSEventNotifyControl ProcessEvent(const RE::TESHitEvent* event, RE::BSTEventSource<RE::TESHitEvent>*) {
        
        auto targetName  = event->target->GetBaseObject()->GetName();

        auto sourceName = event->cause->GetBaseObject()->GetName();

        logger

        return RE::BSEventNotifyControl::kContinue;
    }
};


SKSEPluginLoad(const SKSE::LoadInterface *skse) {
    SKSE::Init(skse);

    RE::ScriptEventSourceHolder* eventSourceHolder = RE::ScriptEventSourceHolder::GetSingleton();


    eventSourceHolder->AddEventSink
   

    return true;
}