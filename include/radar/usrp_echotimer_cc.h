/* -*- c++ -*- */
/*
 * Copyright 2014 Communications Engineering Lab, KIT.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_RADAR_USRP_ECHOTIMER_CC_H
#define INCLUDED_RADAR_USRP_ECHOTIMER_CC_H

#include <gnuradio/tagged_stream_block.h>
#include <radar/api.h>
#include <string>
#include <vector>

namespace gr {
namespace radar {

/*!
 * \brief USRP Echotimer block for radar applications with multi-RX channel support.
 * \ingroup radar
 *
 * This block supports N RX channels using a single RX streamer, following
 * patterns from gr-uhd's usrp_source implementation.
 */
class RADAR_API usrp_echotimer_cc : virtual public gr::tagged_stream_block
{
public:
    typedef std::shared_ptr<usrp_echotimer_cc> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of radar::usrp_echotimer_cc.
     *
     * To avoid accidental use of raw pointers, radar::usrp_echotimer_cc's
     * constructor is in a private implementation
     * class. radar::usrp_echotimer_cc::make is the public interface for
     * creating new instances.
     *
     * \param samp_rate Sample rate in Hz
     * \param center_freq Center frequency in Hz
     * \param num_delay_samps Number of delay samples
     * \param args_tx TX USRP device arguments
     * \param channel_tx TX channel number
     * \param wire_tx TX wire format
     * \param clock_source_tx TX clock source
     * \param time_source_tx TX time source
     * \param antenna_tx TX antenna
     * \param gain_tx TX gain in dB
     * \param timeout_tx TX timeout in seconds
     * \param wait_tx TX wait time before sending
     * \param lo_offset_tx TX LO offset in Hz
     * \param args_rx RX USRP device arguments
     * \param channels_rx Vector of RX channel numbers (e.g., {0, 1})
     * \param wire_rx RX wire format
     * \param clock_source_rx RX clock source
     * \param time_source_rx RX time source
     * \param antennas_rx Vector of RX antennas (one per channel)
     * \param gains_rx Vector of RX gains in dB (one per channel)
     * \param timeout_rx RX timeout in seconds
     * \param wait_rx RX wait time before receiving
     * \param lo_offsets_rx Vector of RX LO offsets in Hz (one per channel)
     * \param len_key Packet length key for tagged stream
     */
    static sptr make(int samp_rate,
                     float center_freq,
                     int num_delay_samps,
                     std::string args_tx,
                     int channel_tx,
                     std::string wire_tx,
                     std::string clock_source_tx,
                     std::string time_source_tx,
                     std::string antenna_tx,
                     float gain_tx,
                     float timeout_tx,
                     float wait_tx,
                     float lo_offset_tx,
                     std::string args_rx,
                     const std::vector<int>& channels_rx,
                     std::string wire_rx,
                     std::string clock_source_rx,
                     std::string time_source_rx,
                     const std::vector<std::string>& antennas_rx,
                     const std::vector<float>& gains_rx,
                     float timeout_rx,
                     float wait_rx,
                     const std::vector<float>& lo_offsets_rx,
                     const std::string& len_key = "packet_len");

    virtual void set_num_delay_samps(int num_samps) = 0;
    virtual void set_rx_gain(float gain, size_t chan = 0) = 0;
    virtual void set_tx_gain(float gain) = 0;
};

} // namespace radar
} // namespace gr

#endif /* INCLUDED_RADAR_USRP_ECHOTIMER_CC_H */
