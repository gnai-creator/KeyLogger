#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>
#include <format>

// Função para tratar teclas pressionadas
void OnKeyPress(uint32_t keyCode) {
    auto message = std::format("Key Pressed: {}", keyCode);
    RE::DebugNotification(message.c_str());
}

// Classe para manipular eventos de entrada
class InputEventHandler : public RE::BSTEventSink<RE::InputEvent> {
public:
    // Implementação correta do método ProcessEvent
    virtual RE::BSEventNotifyControl ProcessEvent(RE::InputEvent** a_event,
                                                  RE::BSTEventSource<RE::InputEvent*>* a_eventSource) override {
        if (!a_event || !*a_event) {
            return RE::BSEventNotifyControl::kContinue;
        }

        // Itera pelos eventos fornecidos
        for (RE::InputEvent* inputEvent = *a_event; inputEvent; inputEvent = inputEvent->next) {
            // Verifica se o evento é do tipo ButtonEvent
            if (const auto* buttonEvent = inputEvent->AsButtonEvent()) {
                if (buttonEvent->IsDown()) {  // Checa se a tecla foi pressionada
                    uint32_t keyCode = buttonEvent->GetIDCode();
                    OnKeyPress(keyCode);
                }
            }
        }

        return RE::BSEventNotifyControl::kContinue;
    }

    // Destrutor virtual para evitar problemas de memória
    virtual ~InputEventHandler() = default;
};

// Função principal para carregar o plugin
bool SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    SKSE::Init(skse);

    auto inputHandler = new InputEventHandler();
    RE::ScriptEventSourceHolder::GetSingleton()->AddEventSink<RE::InputEvent>(inputHandler);

    return true;
}
