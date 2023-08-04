// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include <kernel/types/KProcess.h>
#include <input.h>
#include "IUserManager.h"
#include "IUser.h"

namespace skyline::service::nfp {
    IUser::IUser(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager), attachAvailabilityChangeEvent(std::make_shared<type::KEvent>(state, false)) {}

    Result IUser::Initialize(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        nfpState = State::Initialized;
        return {};
    }
    
    Result IUser::Finalize(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        nfpDeviceState = IUDeviceState::Finalized;
        return {};
    }

    Result IUser::ListDevices(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push<u32>(0);
        return {};
    }
    

    Result IUser::StartDetection(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::StopDetection(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::Mount(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::Unmount(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::OpenApplicationArea(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::GetApplicationArea(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push<u32>(0xD8); // 216 bytes
        return {};
    }

    Result IUser::Flush(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::Restore(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::CreateApplicationArea(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::GetTagInfo(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::GetRegisterInfo(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::GetCommonInfo(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::GetModelInfo(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::AttachActivateEvent(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::AttachDeactivateEvent(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result IUser::GetState(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push(nfpState);
        return {};
    }

    Result IUser::GetApplicationAreaSize(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push<u32>(0xD8); // 216 bytes
        return {};
    }
    
    Result IUser::GetDeviceState(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push(nfpDeviceState);
        return {};
    }

    Result IUser::GetNpadId(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        auto npadHandle{request.Pop<input::NpadDeviceHandle>()};
        response.Push<u32>(0);
        return {};
    }

    Result IUser::AttachAvailabilityChangeEvent(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        auto handle{state.process->InsertItem(attachAvailabilityChangeEvent)};
        Logger::Debug("Attach Availability Change Event Handle: 0x{:X}", handle);
        response.copyHandles.push_back(handle);

        return {};
    }
    
   Result IUser::RecreateApplicationArea(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }
}
