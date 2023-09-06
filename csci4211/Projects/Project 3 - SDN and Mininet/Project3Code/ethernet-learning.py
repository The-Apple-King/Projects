# Copyright 2012 James McCauley
#
# This file is part of POX.
#
# POX is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# POX is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with POX.  If not, see <http://www.gnu.org/licenses/>.

"""
This component is for use with the OpenFlow tutorial.
It acts as a simple hub, but can be modified to act like an L2
learning switch.
It's quite similar to the one for NOX.  Credit where credit due. :)
"""

from pox.core import core
import pox.openflow.libopenflow_01 as of

log = core.getLogger()



class Tutorial (object):
  """
  A Tutorial object is created for each switch that connects.
  A Connection object for that switch is passed to the __init__ function.
  """
  def __init__ (self, connection):
    # Keep track of the connection to the switch so that we can
    # send it messages!
    self.connection = connection

    # This binds our PacketIn event listener
    connection.addListeners(self)

    # Use this table to keep track of which ethernet address is on
    # which switch port (keys are MACs, values are ports).
    self.mac_to_port = {}

  def act_like_switch (self, packet, packet_in, event):
    """
    Implement switch-like behavior.
    """

    src_mac = str(packet.src)
    dst_mac = str(packet.dst)
    
    # save src to input port in dictionary
    if src_mac not in self.mac_to_port:
      self.mac_to_port[src_mac] = event.port
    log.debug("Installing flow...")
    msg = of.ofp_flow_mod()

    # Set fields to match received packet
    msg.match = of.ofp_match.from_packet(packet)

    # Add an output action, and send -- similar to resend_packet()
    if dst_mac in self.mac_to_port:
        log.debug("mac addr saved")
        msg.actions.append(of.ofp_action_output(port = self.mac_to_port[dst_mac]))
    else:
        log.debug("mac addr not found")
        # Flood the packet to all ports except the input port
        msg.actions.append(of.ofp_action_output(port = of.OFPP_FLOOD))
    # Send the flow mod message to the switch
    self.connection.send(msg)
   


  def _handle_PacketIn (self, event):
    """
    Handles packet in messages from the switch.
    """

    packet = event.parsed # This is the parsed packet data.
    if not packet.parsed:
      log.warning("Ignoring incomplete packet")
      return

    packet_in = event.ofp # The actual ofp_packet_in message.

    self.act_like_switch(packet, packet_in, event)



def launch ():
  """
  Starts the component
  """
  def start_switch (event):
    log.debug("Controlling %s" % (event.connection,))
    Tutorial(event.connection)
  core.openflow.addListenerByName("ConnectionUp", start_switch)