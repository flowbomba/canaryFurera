/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2019  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SRC_SERVER_NETWORK_PROTOCOL_PROTOCOLLOGIN_H_
#define SRC_SERVER_NETWORK_PROTOCOL_PROTOCOLLOGIN_H_

#include "server/network/protocol/protocol.h"

class NetworkMessage;
class OutputMessage;

class ProtocolLogin : public Protocol
{
	public:
		// static protocol information
		enum {SERVER_SENDS_FIRST = false};
		enum {PROTOCOL_IDENTIFIER = 0x01};
		enum {USE_CHECKSUM = true};
		static const char* protocol_name() {
			return "login protocol";
		}

		explicit ProtocolLogin(Connection_ptr loginConnection) : Protocol(loginConnection) {}

		void onRecvFirstMessage(NetworkMessage& msg);

	private:
		void disconnectClient(const std::string& message);

		void getCharacterList(const std::string& accountIdentifier, const std::string& password);

		bool oldProtocol = false;
};

#endif  // SRC_SERVER_NETWORK_PROTOCOL_PROTOCOLLOGIN_H_
