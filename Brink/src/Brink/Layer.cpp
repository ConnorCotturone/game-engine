#include "bkpch.h"
#include "Layer.h"

namespace Brink {
	Layer::Layer (const std::string& debugName) : m_DebugName(debugName) {}

	Layer::~Layer() {}
}