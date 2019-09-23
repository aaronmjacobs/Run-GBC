#pragma once

#include "GBC/CPU.h"

#include <array>

namespace GBC
{

namespace
{

const std::array<Operation, 256> kOperations =
{
   /* 0x00 */ Operation(Ins::NOP, Opr::None, Opr::None, 4),
   /* 0x01 */ Operation(Ins::LD, Opr::BC, Opr::Imm16, 12),
   /* 0x02 */ Operation(Ins::LD, Opr::DerefBC, Opr::A, 8),
   /* 0x03 */ Operation(Ins::INC, Opr::BC, Opr::None, 8),
   /* 0x04 */ Operation(Ins::INC, Opr::B, Opr::None, 4),
   /* 0x05 */ Operation(Ins::DEC, Opr::B, Opr::None, 4),
   /* 0x06 */ Operation(Ins::LD, Opr::B, Opr::Imm8, 8),
   /* 0x07 */ Operation(Ins::RLCA, Opr::None, Opr::None, 4),
   /* 0x08 */ Operation(Ins::LD, Opr::DerefImm16, Opr::SP, 20),
   /* 0x09 */ Operation(Ins::ADD, Opr::HL, Opr::BC, 8),
   /* 0x0A */ Operation(Ins::LD, Opr::A, Opr::DerefBC, 8),
   /* 0x0B */ Operation(Ins::DEC, Opr::BC, Opr::None, 8),
   /* 0x0C */ Operation(Ins::INC, Opr::C, Opr::None, 4),
   /* 0x0D */ Operation(Ins::DEC, Opr::C, Opr::None, 4),
   /* 0x0E */ Operation(Ins::LD, Opr::C, Opr::Imm8, 8),
   /* 0x0F */ Operation(Ins::RRCA, Opr::None, Opr::None, 4),
   /* 0x10 */ Operation(Ins::STOP, Opr::None, Opr::None, 4),
   /* 0x11 */ Operation(Ins::LD, Opr::DE, Opr::Imm16, 12),
   /* 0x12 */ Operation(Ins::LD, Opr::DerefDE, Opr::A, 8),
   /* 0x13 */ Operation(Ins::INC, Opr::DE, Opr::None, 8),
   /* 0x14 */ Operation(Ins::INC, Opr::D, Opr::None, 4),
   /* 0x15 */ Operation(Ins::DEC, Opr::D, Opr::None, 4),
   /* 0x16 */ Operation(Ins::LD, Opr::D, Opr::Imm8, 8),
   /* 0x17 */ Operation(Ins::RLA, Opr::None, Opr::None, 4),
   /* 0x18 */ Operation(Ins::JR, Opr::Imm8Signed, Opr::None, 12),
   /* 0x19 */ Operation(Ins::ADD, Opr::HL, Opr::DE, 8),
   /* 0x1A */ Operation(Ins::LD, Opr::A, Opr::DerefDE, 8),
   /* 0x1B */ Operation(Ins::DEC, Opr::DE, Opr::None, 8),
   /* 0x1C */ Operation(Ins::INC, Opr::E, Opr::None, 4),
   /* 0x1D */ Operation(Ins::DEC, Opr::E, Opr::None, 4),
   /* 0x1E */ Operation(Ins::LD, Opr::E, Opr::Imm8, 8),
   /* 0x1F */ Operation(Ins::RRA, Opr::None, Opr::None, 4),
   /* 0x20 */ Operation(Ins::JR, Opr::FlagNZ, Opr::Imm8Signed, 12),
   /* 0x21 */ Operation(Ins::LD, Opr::HL, Opr::Imm16, 12),
   /* 0x22 */ Operation(Ins::LDI, Opr::DerefHL, Opr::A, 8),
   /* 0x23 */ Operation(Ins::INC, Opr::HL, Opr::None, 8),
   /* 0x24 */ Operation(Ins::INC, Opr::H, Opr::None, 4),
   /* 0x25 */ Operation(Ins::DEC, Opr::H, Opr::None, 4),
   /* 0x26 */ Operation(Ins::LD, Opr::H, Opr::Imm8, 8),
   /* 0x27 */ Operation(Ins::DAA, Opr::None, Opr::None, 4),
   /* 0x28 */ Operation(Ins::JR, Opr::FlagZ, Opr::Imm8Signed, 12),
   /* 0x29 */ Operation(Ins::ADD, Opr::HL, Opr::HL, 8),
   /* 0x2A */ Operation(Ins::LDI, Opr::A, Opr::DerefHL, 8),
   /* 0x2B */ Operation(Ins::DEC, Opr::HL, Opr::None, 8),
   /* 0x2C */ Operation(Ins::INC, Opr::L, Opr::None, 4),
   /* 0x2D */ Operation(Ins::DEC, Opr::L, Opr::None, 4),
   /* 0x2E */ Operation(Ins::LD, Opr::L, Opr::Imm8, 8),
   /* 0x2F */ Operation(Ins::CPL, Opr::None, Opr::None, 4),
   /* 0x30 */ Operation(Ins::JR, Opr::FlagNC, Opr::Imm8Signed, 12),
   /* 0x31 */ Operation(Ins::LD, Opr::SP, Opr::Imm16, 12),
   /* 0x32 */ Operation(Ins::LDD, Opr::DerefHL, Opr::A, 8),
   /* 0x33 */ Operation(Ins::INC, Opr::SP, Opr::None, 8),
   /* 0x34 */ Operation(Ins::INC, Opr::DerefHL, Opr::None, 12),
   /* 0x35 */ Operation(Ins::DEC, Opr::DerefHL, Opr::None, 12),
   /* 0x36 */ Operation(Ins::LD, Opr::DerefHL, Opr::Imm8, 12),
   /* 0x37 */ Operation(Ins::SCF, Opr::None, Opr::None, 4),
   /* 0x38 */ Operation(Ins::JR, Opr::FlagC, Opr::Imm8Signed, 12),
   /* 0x39 */ Operation(Ins::ADD, Opr::HL, Opr::SP, 8),
   /* 0x3A */ Operation(Ins::LDD, Opr::A, Opr::DerefHL, 8),
   /* 0x3B */ Operation(Ins::DEC, Opr::SP, Opr::None, 8),
   /* 0x3C */ Operation(Ins::INC, Opr::A, Opr::None, 4),
   /* 0x3D */ Operation(Ins::DEC, Opr::A, Opr::None, 4),
   /* 0x3E */ Operation(Ins::LD, Opr::A, Opr::Imm8, 8),
   /* 0x3F */ Operation(Ins::CCF, Opr::None, Opr::None, 4),
   /* 0x40 */ Operation(Ins::LD, Opr::B, Opr::B, 4),
   /* 0x41 */ Operation(Ins::LD, Opr::B, Opr::C, 4),
   /* 0x42 */ Operation(Ins::LD, Opr::B, Opr::D, 4),
   /* 0x43 */ Operation(Ins::LD, Opr::B, Opr::E, 4),
   /* 0x44 */ Operation(Ins::LD, Opr::B, Opr::H, 4),
   /* 0x45 */ Operation(Ins::LD, Opr::B, Opr::L, 4),
   /* 0x46 */ Operation(Ins::LD, Opr::B, Opr::DerefHL, 8),
   /* 0x47 */ Operation(Ins::LD, Opr::B, Opr::A, 4),
   /* 0x48 */ Operation(Ins::LD, Opr::C, Opr::B, 4),
   /* 0x49 */ Operation(Ins::LD, Opr::C, Opr::C, 4),
   /* 0x4A */ Operation(Ins::LD, Opr::C, Opr::D, 4),
   /* 0x4B */ Operation(Ins::LD, Opr::C, Opr::E, 4),
   /* 0x4C */ Operation(Ins::LD, Opr::C, Opr::H, 4),
   /* 0x4D */ Operation(Ins::LD, Opr::C, Opr::L, 4),
   /* 0x4E */ Operation(Ins::LD, Opr::C, Opr::DerefHL, 8),
   /* 0x4F */ Operation(Ins::LD, Opr::C, Opr::A, 4),
   /* 0x50 */ Operation(Ins::LD, Opr::D, Opr::B, 4),
   /* 0x51 */ Operation(Ins::LD, Opr::D, Opr::C, 4),
   /* 0x52 */ Operation(Ins::LD, Opr::D, Opr::D, 4),
   /* 0x53 */ Operation(Ins::LD, Opr::D, Opr::E, 4),
   /* 0x54 */ Operation(Ins::LD, Opr::D, Opr::H, 4),
   /* 0x55 */ Operation(Ins::LD, Opr::D, Opr::L, 4),
   /* 0x56 */ Operation(Ins::LD, Opr::D, Opr::DerefHL, 8),
   /* 0x57 */ Operation(Ins::LD, Opr::D, Opr::A, 4),
   /* 0x58 */ Operation(Ins::LD, Opr::E, Opr::B, 4),
   /* 0x59 */ Operation(Ins::LD, Opr::E, Opr::C, 4),
   /* 0x5A */ Operation(Ins::LD, Opr::E, Opr::D, 4),
   /* 0x5B */ Operation(Ins::LD, Opr::E, Opr::E, 4),
   /* 0x5C */ Operation(Ins::LD, Opr::E, Opr::H, 4),
   /* 0x5D */ Operation(Ins::LD, Opr::E, Opr::L, 4),
   /* 0x5E */ Operation(Ins::LD, Opr::E, Opr::DerefHL, 8),
   /* 0x5F */ Operation(Ins::LD, Opr::E, Opr::A, 4),
   /* 0x60 */ Operation(Ins::LD, Opr::H, Opr::B, 4),
   /* 0x61 */ Operation(Ins::LD, Opr::H, Opr::C, 4),
   /* 0x62 */ Operation(Ins::LD, Opr::H, Opr::D, 4),
   /* 0x63 */ Operation(Ins::LD, Opr::H, Opr::E, 4),
   /* 0x64 */ Operation(Ins::LD, Opr::H, Opr::H, 4),
   /* 0x65 */ Operation(Ins::LD, Opr::H, Opr::L, 4),
   /* 0x66 */ Operation(Ins::LD, Opr::H, Opr::DerefHL, 8),
   /* 0x67 */ Operation(Ins::LD, Opr::H, Opr::A, 4),
   /* 0x68 */ Operation(Ins::LD, Opr::L, Opr::B, 4),
   /* 0x69 */ Operation(Ins::LD, Opr::L, Opr::C, 4),
   /* 0x6A */ Operation(Ins::LD, Opr::L, Opr::D, 4),
   /* 0x6B */ Operation(Ins::LD, Opr::L, Opr::E, 4),
   /* 0x6C */ Operation(Ins::LD, Opr::L, Opr::H, 4),
   /* 0x6D */ Operation(Ins::LD, Opr::L, Opr::L, 4),
   /* 0x6E */ Operation(Ins::LD, Opr::L, Opr::DerefHL, 8),
   /* 0x6F */ Operation(Ins::LD, Opr::L, Opr::A, 4),
   /* 0x70 */ Operation(Ins::LD, Opr::DerefHL, Opr::B, 8),
   /* 0x71 */ Operation(Ins::LD, Opr::DerefHL, Opr::C, 8),
   /* 0x72 */ Operation(Ins::LD, Opr::DerefHL, Opr::D, 8),
   /* 0x73 */ Operation(Ins::LD, Opr::DerefHL, Opr::E, 8),
   /* 0x74 */ Operation(Ins::LD, Opr::DerefHL, Opr::H, 8),
   /* 0x75 */ Operation(Ins::LD, Opr::DerefHL, Opr::L, 8),
   /* 0x76 */ Operation(Ins::HALT, Opr::None, Opr::None, 4),
   /* 0x77 */ Operation(Ins::LD, Opr::DerefHL, Opr::A, 8),
   /* 0x78 */ Operation(Ins::LD, Opr::A, Opr::B, 4),
   /* 0x79 */ Operation(Ins::LD, Opr::A, Opr::C, 4),
   /* 0x7A */ Operation(Ins::LD, Opr::A, Opr::D, 4),
   /* 0x7B */ Operation(Ins::LD, Opr::A, Opr::E, 4),
   /* 0x7C */ Operation(Ins::LD, Opr::A, Opr::H, 4),
   /* 0x7D */ Operation(Ins::LD, Opr::A, Opr::L, 4),
   /* 0x7E */ Operation(Ins::LD, Opr::A, Opr::DerefHL, 8),
   /* 0x7F */ Operation(Ins::LD, Opr::A, Opr::A, 4),
   /* 0x80 */ Operation(Ins::ADD, Opr::A, Opr::B, 4),
   /* 0x81 */ Operation(Ins::ADD, Opr::A, Opr::C, 4),
   /* 0x82 */ Operation(Ins::ADD, Opr::A, Opr::D, 4),
   /* 0x83 */ Operation(Ins::ADD, Opr::A, Opr::E, 4),
   /* 0x84 */ Operation(Ins::ADD, Opr::A, Opr::H, 4),
   /* 0x85 */ Operation(Ins::ADD, Opr::A, Opr::L, 4),
   /* 0x86 */ Operation(Ins::ADD, Opr::A, Opr::DerefHL, 8),
   /* 0x87 */ Operation(Ins::ADD, Opr::A, Opr::A, 4),
   /* 0x88 */ Operation(Ins::ADC, Opr::A, Opr::B, 4),
   /* 0x89 */ Operation(Ins::ADC, Opr::A, Opr::C, 4),
   /* 0x8A */ Operation(Ins::ADC, Opr::A, Opr::D, 4),
   /* 0x8B */ Operation(Ins::ADC, Opr::A, Opr::E, 4),
   /* 0x8C */ Operation(Ins::ADC, Opr::A, Opr::H, 4),
   /* 0x8D */ Operation(Ins::ADC, Opr::A, Opr::L, 4),
   /* 0x8E */ Operation(Ins::ADC, Opr::A, Opr::DerefHL, 8),
   /* 0x8F */ Operation(Ins::ADC, Opr::A, Opr::A, 4),
   /* 0x90 */ Operation(Ins::SUB, Opr::B, Opr::None, 4),
   /* 0x91 */ Operation(Ins::SUB, Opr::C, Opr::None, 4),
   /* 0x92 */ Operation(Ins::SUB, Opr::D, Opr::None, 4),
   /* 0x93 */ Operation(Ins::SUB, Opr::E, Opr::None, 4),
   /* 0x94 */ Operation(Ins::SUB, Opr::H, Opr::None, 4),
   /* 0x95 */ Operation(Ins::SUB, Opr::L, Opr::None, 4),
   /* 0x96 */ Operation(Ins::SUB, Opr::DerefHL, Opr::None, 8),
   /* 0x97 */ Operation(Ins::SUB, Opr::A, Opr::None, 4),
   /* 0x98 */ Operation(Ins::SBC, Opr::A, Opr::B, 4),
   /* 0x99 */ Operation(Ins::SBC, Opr::A, Opr::C, 4),
   /* 0x9A */ Operation(Ins::SBC, Opr::A, Opr::D, 4),
   /* 0x9B */ Operation(Ins::SBC, Opr::A, Opr::E, 4),
   /* 0x9C */ Operation(Ins::SBC, Opr::A, Opr::H, 4),
   /* 0x9D */ Operation(Ins::SBC, Opr::A, Opr::L, 4),
   /* 0x9E */ Operation(Ins::SBC, Opr::A, Opr::DerefHL, 8),
   /* 0x9F */ Operation(Ins::SBC, Opr::A, Opr::A, 4),
   /* 0xA0 */ Operation(Ins::AND, Opr::B, Opr::None, 4),
   /* 0xA1 */ Operation(Ins::AND, Opr::C, Opr::None, 4),
   /* 0xA2 */ Operation(Ins::AND, Opr::D, Opr::None, 4),
   /* 0xA3 */ Operation(Ins::AND, Opr::E, Opr::None, 4),
   /* 0xA4 */ Operation(Ins::AND, Opr::H, Opr::None, 4),
   /* 0xA5 */ Operation(Ins::AND, Opr::L, Opr::None, 4),
   /* 0xA6 */ Operation(Ins::AND, Opr::DerefHL, Opr::None, 8),
   /* 0xA7 */ Operation(Ins::AND, Opr::A, Opr::None, 4),
   /* 0xA8 */ Operation(Ins::XOR, Opr::B, Opr::None, 4),
   /* 0xA9 */ Operation(Ins::XOR, Opr::C, Opr::None, 4),
   /* 0xAA */ Operation(Ins::XOR, Opr::D, Opr::None, 4),
   /* 0xAB */ Operation(Ins::XOR, Opr::E, Opr::None, 4),
   /* 0xAC */ Operation(Ins::XOR, Opr::H, Opr::None, 4),
   /* 0xAD */ Operation(Ins::XOR, Opr::L, Opr::None, 4),
   /* 0xAE */ Operation(Ins::XOR, Opr::DerefHL, Opr::None, 8),
   /* 0xAF */ Operation(Ins::XOR, Opr::A, Opr::None, 4),
   /* 0xB0 */ Operation(Ins::OR, Opr::B, Opr::None, 4),
   /* 0xB1 */ Operation(Ins::OR, Opr::C, Opr::None, 4),
   /* 0xB2 */ Operation(Ins::OR, Opr::D, Opr::None, 4),
   /* 0xB3 */ Operation(Ins::OR, Opr::E, Opr::None, 4),
   /* 0xB4 */ Operation(Ins::OR, Opr::H, Opr::None, 4),
   /* 0xB5 */ Operation(Ins::OR, Opr::L, Opr::None, 4),
   /* 0xB6 */ Operation(Ins::OR, Opr::DerefHL, Opr::None, 8),
   /* 0xB7 */ Operation(Ins::OR, Opr::A, Opr::None, 4),
   /* 0xB8 */ Operation(Ins::CP, Opr::B, Opr::None, 4),
   /* 0xB9 */ Operation(Ins::CP, Opr::C, Opr::None, 4),
   /* 0xBA */ Operation(Ins::CP, Opr::D, Opr::None, 4),
   /* 0xBB */ Operation(Ins::CP, Opr::E, Opr::None, 4),
   /* 0xBC */ Operation(Ins::CP, Opr::H, Opr::None, 4),
   /* 0xBD */ Operation(Ins::CP, Opr::L, Opr::None, 4),
   /* 0xBE */ Operation(Ins::CP, Opr::DerefHL, Opr::None, 8),
   /* 0xBF */ Operation(Ins::CP, Opr::A, Opr::None, 4),
   /* 0xC0 */ Operation(Ins::RET, Opr::FlagNZ, Opr::None, 20),
   /* 0xC1 */ Operation(Ins::POP, Opr::BC, Opr::None, 12),
   /* 0xC2 */ Operation(Ins::JP, Opr::FlagNZ, Opr::Imm16, 16),
   /* 0xC3 */ Operation(Ins::JP, Opr::Imm16, Opr::None, 16),
   /* 0xC4 */ Operation(Ins::CALL, Opr::FlagNZ, Opr::Imm16, 24),
   /* 0xC5 */ Operation(Ins::PUSH, Opr::BC, Opr::None, 16),
   /* 0xC6 */ Operation(Ins::ADD, Opr::A, Opr::Imm8, 8),
   /* 0xC7 */ Operation(Ins::RST, Opr::Rst00H, Opr::None, 16),
   /* 0xC8 */ Operation(Ins::RET, Opr::FlagZ, Opr::None, 20),
   /* 0xC9 */ Operation(Ins::RET, Opr::None, Opr::None, 16),
   /* 0xCA */ Operation(Ins::JP, Opr::FlagZ, Opr::Imm16, 16),
   /* 0xCB */ Operation(Ins::PREFIX, Opr::CB, Opr::None, 4),
   /* 0xCC */ Operation(Ins::CALL, Opr::FlagZ, Opr::Imm16, 24),
   /* 0xCD */ Operation(Ins::CALL, Opr::Imm16, Opr::None, 24),
   /* 0xCE */ Operation(Ins::ADC, Opr::A, Opr::Imm8, 8),
   /* 0xCF */ Operation(Ins::RST, Opr::Rst08H, Opr::None, 16),
   /* 0xD0 */ Operation(Ins::RET, Opr::FlagNC, Opr::None, 20),
   /* 0xD1 */ Operation(Ins::POP, Opr::DE, Opr::None, 12),
   /* 0xD2 */ Operation(Ins::JP, Opr::FlagNC, Opr::Imm16, 16),
   /* 0xD3 */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xD4 */ Operation(Ins::CALL, Opr::FlagNC, Opr::Imm16, 24),
   /* 0xD5 */ Operation(Ins::PUSH, Opr::DE, Opr::None, 16),
   /* 0xD6 */ Operation(Ins::SUB, Opr::Imm8, Opr::None, 8),
   /* 0xD7 */ Operation(Ins::RST, Opr::Rst10H, Opr::None, 16),
   /* 0xD8 */ Operation(Ins::RET, Opr::FlagC, Opr::None, 20),
   /* 0xD9 */ Operation(Ins::RETI, Opr::None, Opr::None, 16),
   /* 0xDA */ Operation(Ins::JP, Opr::FlagC, Opr::Imm16, 16),
   /* 0xDB */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xDC */ Operation(Ins::CALL, Opr::FlagC, Opr::Imm16, 24),
   /* 0xDD */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xDE */ Operation(Ins::SBC, Opr::A, Opr::Imm8, 8),
   /* 0xDF */ Operation(Ins::RST, Opr::Rst18H, Opr::None, 16),
   /* 0xE0 */ Operation(Ins::LDH, Opr::DerefImm8, Opr::A, 12),
   /* 0xE1 */ Operation(Ins::POP, Opr::HL, Opr::None, 12),
   /* 0xE2 */ Operation(Ins::LD, Opr::DerefC, Opr::A, 8),
   /* 0xE3 */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xE4 */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xE5 */ Operation(Ins::PUSH, Opr::HL, Opr::None, 16),
   /* 0xE6 */ Operation(Ins::AND, Opr::Imm8, Opr::None, 8),
   /* 0xE7 */ Operation(Ins::RST, Opr::Rst20H, Opr::None, 16),
   /* 0xE8 */ Operation(Ins::ADD, Opr::SP, Opr::Imm8Signed, 16),
   /* 0xE9 */ Operation(Ins::JP, Opr::HL, Opr::None, 4),
   /* 0xEA */ Operation(Ins::LD, Opr::DerefImm16, Opr::A, 16),
   /* 0xEB */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xEC */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xED */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xEE */ Operation(Ins::XOR, Opr::Imm8, Opr::None, 8),
   /* 0xEF */ Operation(Ins::RST, Opr::Rst28H, Opr::None, 16),
   /* 0xF0 */ Operation(Ins::LDH, Opr::A, Opr::DerefImm8, 12),
   /* 0xF1 */ Operation(Ins::POP, Opr::AF, Opr::None, 12),
   /* 0xF2 */ Operation(Ins::LD, Opr::A, Opr::DerefC, 8),
   /* 0xF3 */ Operation(Ins::DI, Opr::None, Opr::None, 4),
   /* 0xF4 */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xF5 */ Operation(Ins::PUSH, Opr::AF, Opr::None, 16),
   /* 0xF6 */ Operation(Ins::OR, Opr::Imm8, Opr::None, 8),
   /* 0xF7 */ Operation(Ins::RST, Opr::Rst30H, Opr::None, 16),
   /* 0xF8 */ Operation(Ins::LDHL, Opr::SP, Opr::Imm8Signed, 12),
   /* 0xF9 */ Operation(Ins::LD, Opr::SP, Opr::HL, 8),
   /* 0xFA */ Operation(Ins::LD, Opr::A, Opr::DerefImm16, 16),
   /* 0xFB */ Operation(Ins::EI, Opr::None, Opr::None, 4),
   /* 0xFC */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xFD */ Operation(Ins::Invalid, Opr::None, Opr::None, 0),
   /* 0xFE */ Operation(Ins::CP, Opr::Imm8, Opr::None, 8),
   /* 0xFF */ Operation(Ins::RST, Opr::Rst38H, Opr::None, 16),
};

const std::array<Operation, 256> kCBOperations =
{
   /* 0x00 */ Operation(Ins::RLC, Opr::B, Opr::None, 8),
   /* 0x01 */ Operation(Ins::RLC, Opr::C, Opr::None, 8),
   /* 0x02 */ Operation(Ins::RLC, Opr::D, Opr::None, 8),
   /* 0x03 */ Operation(Ins::RLC, Opr::E, Opr::None, 8),
   /* 0x04 */ Operation(Ins::RLC, Opr::H, Opr::None, 8),
   /* 0x05 */ Operation(Ins::RLC, Opr::L, Opr::None, 8),
   /* 0x06 */ Operation(Ins::RLC, Opr::DerefHL, Opr::None, 16),
   /* 0x07 */ Operation(Ins::RLC, Opr::A, Opr::None, 8),
   /* 0x08 */ Operation(Ins::RRC, Opr::B, Opr::None, 8),
   /* 0x09 */ Operation(Ins::RRC, Opr::C, Opr::None, 8),
   /* 0x0A */ Operation(Ins::RRC, Opr::D, Opr::None, 8),
   /* 0x0B */ Operation(Ins::RRC, Opr::E, Opr::None, 8),
   /* 0x0C */ Operation(Ins::RRC, Opr::H, Opr::None, 8),
   /* 0x0D */ Operation(Ins::RRC, Opr::L, Opr::None, 8),
   /* 0x0E */ Operation(Ins::RRC, Opr::DerefHL, Opr::None, 16),
   /* 0x0F */ Operation(Ins::RRC, Opr::A, Opr::None, 8),
   /* 0x10 */ Operation(Ins::RL, Opr::B, Opr::None, 8),
   /* 0x11 */ Operation(Ins::RL, Opr::C, Opr::None, 8),
   /* 0x12 */ Operation(Ins::RL, Opr::D, Opr::None, 8),
   /* 0x13 */ Operation(Ins::RL, Opr::E, Opr::None, 8),
   /* 0x14 */ Operation(Ins::RL, Opr::H, Opr::None, 8),
   /* 0x15 */ Operation(Ins::RL, Opr::L, Opr::None, 8),
   /* 0x16 */ Operation(Ins::RL, Opr::DerefHL, Opr::None, 16),
   /* 0x17 */ Operation(Ins::RL, Opr::A, Opr::None, 8),
   /* 0x18 */ Operation(Ins::RR, Opr::B, Opr::None, 8),
   /* 0x19 */ Operation(Ins::RR, Opr::C, Opr::None, 8),
   /* 0x1A */ Operation(Ins::RR, Opr::D, Opr::None, 8),
   /* 0x1B */ Operation(Ins::RR, Opr::E, Opr::None, 8),
   /* 0x1C */ Operation(Ins::RR, Opr::H, Opr::None, 8),
   /* 0x1D */ Operation(Ins::RR, Opr::L, Opr::None, 8),
   /* 0x1E */ Operation(Ins::RR, Opr::DerefHL, Opr::None, 16),
   /* 0x1F */ Operation(Ins::RR, Opr::A, Opr::None, 8),
   /* 0x20 */ Operation(Ins::SLA, Opr::B, Opr::None, 8),
   /* 0x21 */ Operation(Ins::SLA, Opr::C, Opr::None, 8),
   /* 0x22 */ Operation(Ins::SLA, Opr::D, Opr::None, 8),
   /* 0x23 */ Operation(Ins::SLA, Opr::E, Opr::None, 8),
   /* 0x24 */ Operation(Ins::SLA, Opr::H, Opr::None, 8),
   /* 0x25 */ Operation(Ins::SLA, Opr::L, Opr::None, 8),
   /* 0x26 */ Operation(Ins::SLA, Opr::DerefHL, Opr::None, 16),
   /* 0x27 */ Operation(Ins::SLA, Opr::A, Opr::None, 8),
   /* 0x28 */ Operation(Ins::SRA, Opr::B, Opr::None, 8),
   /* 0x29 */ Operation(Ins::SRA, Opr::C, Opr::None, 8),
   /* 0x2A */ Operation(Ins::SRA, Opr::D, Opr::None, 8),
   /* 0x2B */ Operation(Ins::SRA, Opr::E, Opr::None, 8),
   /* 0x2C */ Operation(Ins::SRA, Opr::H, Opr::None, 8),
   /* 0x2D */ Operation(Ins::SRA, Opr::L, Opr::None, 8),
   /* 0x2E */ Operation(Ins::SRA, Opr::DerefHL, Opr::None, 16),
   /* 0x2F */ Operation(Ins::SRA, Opr::A, Opr::None, 8),
   /* 0x30 */ Operation(Ins::SWAP, Opr::B, Opr::None, 8),
   /* 0x31 */ Operation(Ins::SWAP, Opr::C, Opr::None, 8),
   /* 0x32 */ Operation(Ins::SWAP, Opr::D, Opr::None, 8),
   /* 0x33 */ Operation(Ins::SWAP, Opr::E, Opr::None, 8),
   /* 0x34 */ Operation(Ins::SWAP, Opr::H, Opr::None, 8),
   /* 0x35 */ Operation(Ins::SWAP, Opr::L, Opr::None, 8),
   /* 0x36 */ Operation(Ins::SWAP, Opr::DerefHL, Opr::None, 16),
   /* 0x37 */ Operation(Ins::SWAP, Opr::A, Opr::None, 8),
   /* 0x38 */ Operation(Ins::SRL, Opr::B, Opr::None, 8),
   /* 0x39 */ Operation(Ins::SRL, Opr::C, Opr::None, 8),
   /* 0x3A */ Operation(Ins::SRL, Opr::D, Opr::None, 8),
   /* 0x3B */ Operation(Ins::SRL, Opr::E, Opr::None, 8),
   /* 0x3C */ Operation(Ins::SRL, Opr::H, Opr::None, 8),
   /* 0x3D */ Operation(Ins::SRL, Opr::L, Opr::None, 8),
   /* 0x3E */ Operation(Ins::SRL, Opr::DerefHL, Opr::None, 16),
   /* 0x3F */ Operation(Ins::SRL, Opr::A, Opr::None, 8),
   /* 0x40 */ Operation(Ins::BIT, Opr::Bit0, Opr::B, 8),
   /* 0x41 */ Operation(Ins::BIT, Opr::Bit0, Opr::C, 8),
   /* 0x42 */ Operation(Ins::BIT, Opr::Bit0, Opr::D, 8),
   /* 0x43 */ Operation(Ins::BIT, Opr::Bit0, Opr::E, 8),
   /* 0x44 */ Operation(Ins::BIT, Opr::Bit0, Opr::H, 8),
   /* 0x45 */ Operation(Ins::BIT, Opr::Bit0, Opr::L, 8),
   /* 0x46 */ Operation(Ins::BIT, Opr::Bit0, Opr::DerefHL, 16),
   /* 0x47 */ Operation(Ins::BIT, Opr::Bit0, Opr::A, 8),
   /* 0x48 */ Operation(Ins::BIT, Opr::Bit1, Opr::B, 8),
   /* 0x49 */ Operation(Ins::BIT, Opr::Bit1, Opr::C, 8),
   /* 0x4A */ Operation(Ins::BIT, Opr::Bit1, Opr::D, 8),
   /* 0x4B */ Operation(Ins::BIT, Opr::Bit1, Opr::E, 8),
   /* 0x4C */ Operation(Ins::BIT, Opr::Bit1, Opr::H, 8),
   /* 0x4D */ Operation(Ins::BIT, Opr::Bit1, Opr::L, 8),
   /* 0x4E */ Operation(Ins::BIT, Opr::Bit1, Opr::DerefHL, 16),
   /* 0x4F */ Operation(Ins::BIT, Opr::Bit1, Opr::A, 8),
   /* 0x50 */ Operation(Ins::BIT, Opr::Bit2, Opr::B, 8),
   /* 0x51 */ Operation(Ins::BIT, Opr::Bit2, Opr::C, 8),
   /* 0x52 */ Operation(Ins::BIT, Opr::Bit2, Opr::D, 8),
   /* 0x53 */ Operation(Ins::BIT, Opr::Bit2, Opr::E, 8),
   /* 0x54 */ Operation(Ins::BIT, Opr::Bit2, Opr::H, 8),
   /* 0x55 */ Operation(Ins::BIT, Opr::Bit2, Opr::L, 8),
   /* 0x56 */ Operation(Ins::BIT, Opr::Bit2, Opr::DerefHL, 16),
   /* 0x57 */ Operation(Ins::BIT, Opr::Bit2, Opr::A, 8),
   /* 0x58 */ Operation(Ins::BIT, Opr::Bit3, Opr::B, 8),
   /* 0x59 */ Operation(Ins::BIT, Opr::Bit3, Opr::C, 8),
   /* 0x5A */ Operation(Ins::BIT, Opr::Bit3, Opr::D, 8),
   /* 0x5B */ Operation(Ins::BIT, Opr::Bit3, Opr::E, 8),
   /* 0x5C */ Operation(Ins::BIT, Opr::Bit3, Opr::H, 8),
   /* 0x5D */ Operation(Ins::BIT, Opr::Bit3, Opr::L, 8),
   /* 0x5E */ Operation(Ins::BIT, Opr::Bit3, Opr::DerefHL, 16),
   /* 0x5F */ Operation(Ins::BIT, Opr::Bit3, Opr::A, 8),
   /* 0x60 */ Operation(Ins::BIT, Opr::Bit4, Opr::B, 8),
   /* 0x61 */ Operation(Ins::BIT, Opr::Bit4, Opr::C, 8),
   /* 0x62 */ Operation(Ins::BIT, Opr::Bit4, Opr::D, 8),
   /* 0x63 */ Operation(Ins::BIT, Opr::Bit4, Opr::E, 8),
   /* 0x64 */ Operation(Ins::BIT, Opr::Bit4, Opr::H, 8),
   /* 0x65 */ Operation(Ins::BIT, Opr::Bit4, Opr::L, 8),
   /* 0x66 */ Operation(Ins::BIT, Opr::Bit4, Opr::DerefHL, 16),
   /* 0x67 */ Operation(Ins::BIT, Opr::Bit4, Opr::A, 8),
   /* 0x68 */ Operation(Ins::BIT, Opr::Bit5, Opr::B, 8),
   /* 0x69 */ Operation(Ins::BIT, Opr::Bit5, Opr::C, 8),
   /* 0x6A */ Operation(Ins::BIT, Opr::Bit5, Opr::D, 8),
   /* 0x6B */ Operation(Ins::BIT, Opr::Bit5, Opr::E, 8),
   /* 0x6C */ Operation(Ins::BIT, Opr::Bit5, Opr::H, 8),
   /* 0x6D */ Operation(Ins::BIT, Opr::Bit5, Opr::L, 8),
   /* 0x6E */ Operation(Ins::BIT, Opr::Bit5, Opr::DerefHL, 16),
   /* 0x6F */ Operation(Ins::BIT, Opr::Bit5, Opr::A, 8),
   /* 0x70 */ Operation(Ins::BIT, Opr::Bit6, Opr::B, 8),
   /* 0x71 */ Operation(Ins::BIT, Opr::Bit6, Opr::C, 8),
   /* 0x72 */ Operation(Ins::BIT, Opr::Bit6, Opr::D, 8),
   /* 0x73 */ Operation(Ins::BIT, Opr::Bit6, Opr::E, 8),
   /* 0x74 */ Operation(Ins::BIT, Opr::Bit6, Opr::H, 8),
   /* 0x75 */ Operation(Ins::BIT, Opr::Bit6, Opr::L, 8),
   /* 0x76 */ Operation(Ins::BIT, Opr::Bit6, Opr::DerefHL, 16),
   /* 0x77 */ Operation(Ins::BIT, Opr::Bit6, Opr::A, 8),
   /* 0x78 */ Operation(Ins::BIT, Opr::Bit7, Opr::B, 8),
   /* 0x79 */ Operation(Ins::BIT, Opr::Bit7, Opr::C, 8),
   /* 0x7A */ Operation(Ins::BIT, Opr::Bit7, Opr::D, 8),
   /* 0x7B */ Operation(Ins::BIT, Opr::Bit7, Opr::E, 8),
   /* 0x7C */ Operation(Ins::BIT, Opr::Bit7, Opr::H, 8),
   /* 0x7D */ Operation(Ins::BIT, Opr::Bit7, Opr::L, 8),
   /* 0x7E */ Operation(Ins::BIT, Opr::Bit7, Opr::DerefHL, 16),
   /* 0x7F */ Operation(Ins::BIT, Opr::Bit7, Opr::A, 8),
   /* 0x80 */ Operation(Ins::RES, Opr::Bit0, Opr::B, 8),
   /* 0x81 */ Operation(Ins::RES, Opr::Bit0, Opr::C, 8),
   /* 0x82 */ Operation(Ins::RES, Opr::Bit0, Opr::D, 8),
   /* 0x83 */ Operation(Ins::RES, Opr::Bit0, Opr::E, 8),
   /* 0x84 */ Operation(Ins::RES, Opr::Bit0, Opr::H, 8),
   /* 0x85 */ Operation(Ins::RES, Opr::Bit0, Opr::L, 8),
   /* 0x86 */ Operation(Ins::RES, Opr::Bit0, Opr::DerefHL, 16),
   /* 0x87 */ Operation(Ins::RES, Opr::Bit0, Opr::A, 8),
   /* 0x88 */ Operation(Ins::RES, Opr::Bit1, Opr::B, 8),
   /* 0x89 */ Operation(Ins::RES, Opr::Bit1, Opr::C, 8),
   /* 0x8A */ Operation(Ins::RES, Opr::Bit1, Opr::D, 8),
   /* 0x8B */ Operation(Ins::RES, Opr::Bit1, Opr::E, 8),
   /* 0x8C */ Operation(Ins::RES, Opr::Bit1, Opr::H, 8),
   /* 0x8D */ Operation(Ins::RES, Opr::Bit1, Opr::L, 8),
   /* 0x8E */ Operation(Ins::RES, Opr::Bit1, Opr::DerefHL, 16),
   /* 0x8F */ Operation(Ins::RES, Opr::Bit1, Opr::A, 8),
   /* 0x90 */ Operation(Ins::RES, Opr::Bit2, Opr::B, 8),
   /* 0x91 */ Operation(Ins::RES, Opr::Bit2, Opr::C, 8),
   /* 0x92 */ Operation(Ins::RES, Opr::Bit2, Opr::D, 8),
   /* 0x93 */ Operation(Ins::RES, Opr::Bit2, Opr::E, 8),
   /* 0x94 */ Operation(Ins::RES, Opr::Bit2, Opr::H, 8),
   /* 0x95 */ Operation(Ins::RES, Opr::Bit2, Opr::L, 8),
   /* 0x96 */ Operation(Ins::RES, Opr::Bit2, Opr::DerefHL, 16),
   /* 0x97 */ Operation(Ins::RES, Opr::Bit2, Opr::A, 8),
   /* 0x98 */ Operation(Ins::RES, Opr::Bit3, Opr::B, 8),
   /* 0x99 */ Operation(Ins::RES, Opr::Bit3, Opr::C, 8),
   /* 0x9A */ Operation(Ins::RES, Opr::Bit3, Opr::D, 8),
   /* 0x9B */ Operation(Ins::RES, Opr::Bit3, Opr::E, 8),
   /* 0x9C */ Operation(Ins::RES, Opr::Bit3, Opr::H, 8),
   /* 0x9D */ Operation(Ins::RES, Opr::Bit3, Opr::L, 8),
   /* 0x9E */ Operation(Ins::RES, Opr::Bit3, Opr::DerefHL, 16),
   /* 0x9F */ Operation(Ins::RES, Opr::Bit3, Opr::A, 8),
   /* 0xA0 */ Operation(Ins::RES, Opr::Bit4, Opr::B, 8),
   /* 0xA1 */ Operation(Ins::RES, Opr::Bit4, Opr::C, 8),
   /* 0xA2 */ Operation(Ins::RES, Opr::Bit4, Opr::D, 8),
   /* 0xA3 */ Operation(Ins::RES, Opr::Bit4, Opr::E, 8),
   /* 0xA4 */ Operation(Ins::RES, Opr::Bit4, Opr::H, 8),
   /* 0xA5 */ Operation(Ins::RES, Opr::Bit4, Opr::L, 8),
   /* 0xA6 */ Operation(Ins::RES, Opr::Bit4, Opr::DerefHL, 16),
   /* 0xA7 */ Operation(Ins::RES, Opr::Bit4, Opr::A, 8),
   /* 0xA8 */ Operation(Ins::RES, Opr::Bit5, Opr::B, 8),
   /* 0xA9 */ Operation(Ins::RES, Opr::Bit5, Opr::C, 8),
   /* 0xAA */ Operation(Ins::RES, Opr::Bit5, Opr::D, 8),
   /* 0xAB */ Operation(Ins::RES, Opr::Bit5, Opr::E, 8),
   /* 0xAC */ Operation(Ins::RES, Opr::Bit5, Opr::H, 8),
   /* 0xAD */ Operation(Ins::RES, Opr::Bit5, Opr::L, 8),
   /* 0xAE */ Operation(Ins::RES, Opr::Bit5, Opr::DerefHL, 16),
   /* 0xAF */ Operation(Ins::RES, Opr::Bit5, Opr::A, 8),
   /* 0xB0 */ Operation(Ins::RES, Opr::Bit6, Opr::B, 8),
   /* 0xB1 */ Operation(Ins::RES, Opr::Bit6, Opr::C, 8),
   /* 0xB2 */ Operation(Ins::RES, Opr::Bit6, Opr::D, 8),
   /* 0xB3 */ Operation(Ins::RES, Opr::Bit6, Opr::E, 8),
   /* 0xB4 */ Operation(Ins::RES, Opr::Bit6, Opr::H, 8),
   /* 0xB5 */ Operation(Ins::RES, Opr::Bit6, Opr::L, 8),
   /* 0xB6 */ Operation(Ins::RES, Opr::Bit6, Opr::DerefHL, 16),
   /* 0xB7 */ Operation(Ins::RES, Opr::Bit6, Opr::A, 8),
   /* 0xB8 */ Operation(Ins::RES, Opr::Bit7, Opr::B, 8),
   /* 0xB9 */ Operation(Ins::RES, Opr::Bit7, Opr::C, 8),
   /* 0xBA */ Operation(Ins::RES, Opr::Bit7, Opr::D, 8),
   /* 0xBB */ Operation(Ins::RES, Opr::Bit7, Opr::E, 8),
   /* 0xBC */ Operation(Ins::RES, Opr::Bit7, Opr::H, 8),
   /* 0xBD */ Operation(Ins::RES, Opr::Bit7, Opr::L, 8),
   /* 0xBE */ Operation(Ins::RES, Opr::Bit7, Opr::DerefHL, 16),
   /* 0xBF */ Operation(Ins::RES, Opr::Bit7, Opr::A, 8),
   /* 0xC0 */ Operation(Ins::SET, Opr::Bit0, Opr::B, 8),
   /* 0xC1 */ Operation(Ins::SET, Opr::Bit0, Opr::C, 8),
   /* 0xC2 */ Operation(Ins::SET, Opr::Bit0, Opr::D, 8),
   /* 0xC3 */ Operation(Ins::SET, Opr::Bit0, Opr::E, 8),
   /* 0xC4 */ Operation(Ins::SET, Opr::Bit0, Opr::H, 8),
   /* 0xC5 */ Operation(Ins::SET, Opr::Bit0, Opr::L, 8),
   /* 0xC6 */ Operation(Ins::SET, Opr::Bit0, Opr::DerefHL, 16),
   /* 0xC7 */ Operation(Ins::SET, Opr::Bit0, Opr::A, 8),
   /* 0xC8 */ Operation(Ins::SET, Opr::Bit1, Opr::B, 8),
   /* 0xC9 */ Operation(Ins::SET, Opr::Bit1, Opr::C, 8),
   /* 0xCA */ Operation(Ins::SET, Opr::Bit1, Opr::D, 8),
   /* 0xCB */ Operation(Ins::SET, Opr::Bit1, Opr::E, 8),
   /* 0xCC */ Operation(Ins::SET, Opr::Bit1, Opr::H, 8),
   /* 0xCD */ Operation(Ins::SET, Opr::Bit1, Opr::L, 8),
   /* 0xCE */ Operation(Ins::SET, Opr::Bit1, Opr::DerefHL, 16),
   /* 0xCF */ Operation(Ins::SET, Opr::Bit1, Opr::A, 8),
   /* 0xD0 */ Operation(Ins::SET, Opr::Bit2, Opr::B, 8),
   /* 0xD1 */ Operation(Ins::SET, Opr::Bit2, Opr::C, 8),
   /* 0xD2 */ Operation(Ins::SET, Opr::Bit2, Opr::D, 8),
   /* 0xD3 */ Operation(Ins::SET, Opr::Bit2, Opr::E, 8),
   /* 0xD4 */ Operation(Ins::SET, Opr::Bit2, Opr::H, 8),
   /* 0xD5 */ Operation(Ins::SET, Opr::Bit2, Opr::L, 8),
   /* 0xD6 */ Operation(Ins::SET, Opr::Bit2, Opr::DerefHL, 16),
   /* 0xD7 */ Operation(Ins::SET, Opr::Bit2, Opr::A, 8),
   /* 0xD8 */ Operation(Ins::SET, Opr::Bit3, Opr::B, 8),
   /* 0xD9 */ Operation(Ins::SET, Opr::Bit3, Opr::C, 8),
   /* 0xDA */ Operation(Ins::SET, Opr::Bit3, Opr::D, 8),
   /* 0xDB */ Operation(Ins::SET, Opr::Bit3, Opr::E, 8),
   /* 0xDC */ Operation(Ins::SET, Opr::Bit3, Opr::H, 8),
   /* 0xDD */ Operation(Ins::SET, Opr::Bit3, Opr::L, 8),
   /* 0xDE */ Operation(Ins::SET, Opr::Bit3, Opr::DerefHL, 16),
   /* 0xDF */ Operation(Ins::SET, Opr::Bit3, Opr::A, 8),
   /* 0xE0 */ Operation(Ins::SET, Opr::Bit4, Opr::B, 8),
   /* 0xE1 */ Operation(Ins::SET, Opr::Bit4, Opr::C, 8),
   /* 0xE2 */ Operation(Ins::SET, Opr::Bit4, Opr::D, 8),
   /* 0xE3 */ Operation(Ins::SET, Opr::Bit4, Opr::E, 8),
   /* 0xE4 */ Operation(Ins::SET, Opr::Bit4, Opr::H, 8),
   /* 0xE5 */ Operation(Ins::SET, Opr::Bit4, Opr::L, 8),
   /* 0xE6 */ Operation(Ins::SET, Opr::Bit4, Opr::DerefHL, 16),
   /* 0xE7 */ Operation(Ins::SET, Opr::Bit4, Opr::A, 8),
   /* 0xE8 */ Operation(Ins::SET, Opr::Bit5, Opr::B, 8),
   /* 0xE9 */ Operation(Ins::SET, Opr::Bit5, Opr::C, 8),
   /* 0xEA */ Operation(Ins::SET, Opr::Bit5, Opr::D, 8),
   /* 0xEB */ Operation(Ins::SET, Opr::Bit5, Opr::E, 8),
   /* 0xEC */ Operation(Ins::SET, Opr::Bit5, Opr::H, 8),
   /* 0xED */ Operation(Ins::SET, Opr::Bit5, Opr::L, 8),
   /* 0xEE */ Operation(Ins::SET, Opr::Bit5, Opr::DerefHL, 16),
   /* 0xEF */ Operation(Ins::SET, Opr::Bit5, Opr::A, 8),
   /* 0xF0 */ Operation(Ins::SET, Opr::Bit6, Opr::B, 8),
   /* 0xF1 */ Operation(Ins::SET, Opr::Bit6, Opr::C, 8),
   /* 0xF2 */ Operation(Ins::SET, Opr::Bit6, Opr::D, 8),
   /* 0xF3 */ Operation(Ins::SET, Opr::Bit6, Opr::E, 8),
   /* 0xF4 */ Operation(Ins::SET, Opr::Bit6, Opr::H, 8),
   /* 0xF5 */ Operation(Ins::SET, Opr::Bit6, Opr::L, 8),
   /* 0xF6 */ Operation(Ins::SET, Opr::Bit6, Opr::DerefHL, 16),
   /* 0xF7 */ Operation(Ins::SET, Opr::Bit6, Opr::A, 8),
   /* 0xF8 */ Operation(Ins::SET, Opr::Bit7, Opr::B, 8),
   /* 0xF9 */ Operation(Ins::SET, Opr::Bit7, Opr::C, 8),
   /* 0xFA */ Operation(Ins::SET, Opr::Bit7, Opr::D, 8),
   /* 0xFB */ Operation(Ins::SET, Opr::Bit7, Opr::E, 8),
   /* 0xFC */ Operation(Ins::SET, Opr::Bit7, Opr::H, 8),
   /* 0xFD */ Operation(Ins::SET, Opr::Bit7, Opr::L, 8),
   /* 0xFE */ Operation(Ins::SET, Opr::Bit7, Opr::DerefHL, 16),
   /* 0xFF */ Operation(Ins::SET, Opr::Bit7, Opr::A, 8),
};

} // namespace

} // namespace GBC
