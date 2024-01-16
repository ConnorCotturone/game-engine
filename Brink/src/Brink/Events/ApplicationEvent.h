#pragma once

#include "Event.h"

namespace Brink {
	class BRINK_API WindowResizeEvent : public Event {
		private :
			unsigned int m_Width, m_Height;
		public :
			WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

			inline unsigned int getHeight() const { return m_Height; }
			inline unsigned int getWidth() const { return m_Width; }

			std::string ToString() const override {
				std::stringstream ss;
				ss << "WindowResizeEvent (W, H): " << m_Width << ", " << m_Height;
				return ss.str();
			}

			EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BRINK_API WindowCloseEvent : public Event {
		public:
			WindowCloseEvent() {}

			EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BRINK_API AppTickEvent : public Event {
		public:
			AppTickEvent() {}

			EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BRINK_API AppUpdateEvent : public Event {
		public:
			AppUpdateEvent() {}

			EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class BRINK_API AppRenderEvent : public Event {
		public:
			AppRenderEvent() {}

			EVENT_CLASS_TYPE(AppRender)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};
}