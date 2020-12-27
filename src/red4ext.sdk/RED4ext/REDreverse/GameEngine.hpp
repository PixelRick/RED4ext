#pragma once

#include <cstdint>

#include <RED4ext/RED4define.hpp>
#include <RED4ext/REDreverse/RTTI/CRTTIBaseType.hpp>
#include <RED4ext/REDreverse/Scripting/IScriptable.hpp>

namespace RED4ext::REDreverse
{
    struct BaseGameEngine
    {
        virtual void sub_0() = 0;
    };

    RED4EXT_ASSERT_SIZE(BaseGameEngine, 0x8);

    struct CBaseEngine : BaseGameEngine
    {
    };

    RED4EXT_ASSERT_SIZE(CBaseEngine, 0x8);

    struct CGameEngine : CBaseEngine
    {
        struct CGameFramework
        {
            struct GameInstance
            {
                virtual ~GameInstance() = 0;
                virtual Scripting::IScriptable* GetTypeInstance(const CRTTIBaseType* aClass) = 0;
            };

            RED4EXT_ASSERT_SIZE(GameInstance, 0x8);

            int8_t unk0[0x10];
            GameInstance* gameInstance;
        };

        struct UnkC0
        {
            uint8_t pad0[0x140];
            uint32_t unk140;
            uint8_t pad144[0x164 - 0x144];
            uint32_t unk164;
            void* hWnd;
            uint8_t pad170[0x9];
            uint8_t isClipped;
        };

        RED4EXT_ASSERT_SIZE(CGameFramework, 0x18);
        RED4EXT_ASSERT_OFFSET(CGameFramework, gameInstance, 0x10);

        static CGameEngine* Get();

        int8_t pad8[0xC0 - 0x8];
        UnkC0* unkC0;
        int8_t padC8[0x260 - 0xC8];
        CGameFramework* framework;
    };

    RED4EXT_ASSERT_SIZE(CGameEngine, 0x268);
    RED4EXT_ASSERT_OFFSET(CGameEngine, framework, 0x260);
}
