#pragma once

using namespace geode::prelude;

class DialogCallback : public CCNode, public DialogDelegate {
public:
	std::function<void()> m_callback;
	virtual void dialogClosed(DialogLayer* p0) { if (m_callback) m_callback(); }
};