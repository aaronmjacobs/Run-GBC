#ifndef GBC_DEVICE_H
#define GBC_DEVICE_H

#include "Pointers.h"

#include "gbc/CPU.h"
#include "gbc/Memory.h"

namespace GBC {

class Device {
public:
   Device();

   void tick(float dt);

   void setCartridge(UPtr<class Cartridge>&& cartridge);

private:
   void tickDiv(uint64_t cycles);

   void tickTima(uint64_t cycles);

   Memory memory;
   CPU cpu;

   UPtr<class Cartridge> cart;

   uint64_t divCycles;
   uint64_t timaCycles;
};

} // namespace GBC

#endif
