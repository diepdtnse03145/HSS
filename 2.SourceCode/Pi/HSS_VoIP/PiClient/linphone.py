#!/usr/bin/env python
 
import linphone
import logging
import signal
import time
 
class SecurityCamera:
  def __init__(self, username='', password='', snd_capture='', snd_playback=''):
    self.quit = False
    callbacks = {
      'call_state_changed': self.call_state_changed,
    }
 
    # Configure the linphone core
    logging.basicConfig(level=logging.INFO)
    signal.signal(signal.SIGINT, self.signal_handler)
    linphone.set_log_handler(self.log_handler)
    self.core = linphone.Core.new(callbacks, None, None)
    self.core.max_calls = 4
    self.core.echo_cancellation_enabled = False
    self.core.video_capture_enabled = False
    self.core.video_display_enabled = False
    self.core.stun_server = 'stun.linphone.org'
    self.core.firewall_policy = linphone.FirewallPolicy.PolicyUseIce
	if len(snd_capture):
      self.core.capture_device = snd_capture
    if len(snd_playback):
      self.core.playback_device = snd_playback
	
    # Only enable PCMU and PCMA audio codecs
    for codec in self.core.audio_codecs:
      if codec.mime_type == "PCMA" or codec.mime_type == "PCMU":
        self.core.enable_payload_type(codec, True)
      else:
        self.core.enable_payload_type(codec, False)
 
    self.configure_sip_account(username, password)
 
  def signal_handler(self, signal, frame):
    self.core.terminate_all_calls()
    self.quit = True
 
  def log_handler(self, level, msg):
    method = getattr(logging, level)
    method(msg)
 
  def call_state_changed(self, core, call, state, message):
    if state == linphone.CallState.IncomingReceived:
        params = core.create_call_params(call)
        core.accept_call_with_params(call, params)
 
  def configure_sip_account(self, username, password):
    # Configure the SIP account
    proxy_cfg = self.core.create_proxy_config()
    proxy_cfg.identity_address = self.core.create_address('sip:{username}@sip.linphone.org'.format(username=username))
    proxy_cfg.server_addr = 'sip:sip.linphone.org;transport=tls'
    proxy_cfg.register_enabled = True
    self.core.add_proxy_config(proxy_cfg)
    auth_info = self.core.create_auth_info(username, None, password, None, None, 'sip.linphone.org')
    self.core.add_auth_info(auth_info)
 
  def run(self):
    while not self.quit:
      self.core.iterate()
      time.sleep(0.03)
 
def main():
  cam = SecurityCamera(username='cuongtv.fl', password='tinhte123', snd_capture='ALSA: USB PnP Sound Device')
  cam.run()
 
main()
