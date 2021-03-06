#include "long_trade.h"

LongTrade::LongTrade(unsigned int id, std::shared_ptr<Tick> tick): Trade(id, tick) {
	m_filled_open_price = tick->get_ask();
}

LongTrade::~LongTrade() { }

void LongTrade::close(std::shared_ptr<Tick> tick) {
	m_open = false;
	record_tick(tick);

	m_filled_close_price = tick->get_bid();
	m_closed_at = tick->get_time();
	m_close_bid = tick->get_bid();
	m_close_ask = tick->get_ask();
}

float LongTrade::profit() {
	if(m_open) {
		return m_filled_open_price - get_last_tick()->get_bid();
	} else {
		return m_filled_open_price - m_filled_close_price;
	}
}
