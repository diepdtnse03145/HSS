#include <linphone/linphonecore.h>
#include <bits/stdc++.h>

#define USER_CER "/home/mio/Documents/linphone-desktop/OUTPUT/share/linphone/rootca.pem"
#define USER_CER_PATH "/home/mio/Documents/Moe"

void *HSS_waiting_callback(LinphoneCore *lc, void *ctx, LinphoneWaitingState ws, const char *purpose, float progress)
{
    std::cout<<__FUNCTION__<<" : "<<"Waiting for "<<
               purpose<<" : "<<progress<<std::endl;
}

static void registration_state_changed(struct _LinphoneCore *lc, LinphoneProxyConfig *cfg, LinphoneRegistrationState cstate, const char *message){
    printf("New registration state %s for user id [%s] at proxy [%s]\n"
           ,linphone_registration_state_to_string(cstate)
           ,linphone_proxy_config_get_identity(cfg)
           ,linphone_proxy_config_get_addr(cfg));
}

void text_received(LinphoneCore *lc, LinphoneChatRoom *room, const LinphoneAddress *from, const char *message) {
        printf(" Message [%s] received from [%s] \n",message,linphone_address_as_string (from));
}

void message_received_S(LinphoneCore *lc, LinphoneChatRoom *room, LinphoneChatMessage *message) {
//        printf(" Message [%s] received from [%s] \n",message,linphone_address_as_string (from));
    std::cout<<__FUNCTION__<<std::endl;
}

int main(int argc, char** argv)
{
    LinphoneCoreVTable vtable = {0};
    vtable.registration_state_changed=registration_state_changed;
    vtable.text_received=text_received;
    vtable.message_received=message_received_S;

    auto const the_core = linphone_core_new(&vtable, nullptr, nullptr, nullptr);
    linphone_core_migrate_to_multi_transport(the_core);
    linphone_core_set_user_agent(the_core, "HSS", "1.0");
    linphone_core_set_waiting_callback(the_core, HSS_waiting_callback, nullptr);

    linphone_core_set_user_certificates_path(the_core, USER_CER_PATH);
    linphone_core_enable_video_capture(the_core, false);
    linphone_core_enable_video_display(the_core, false);

    auto auth = linphone_auth_info_new("diepdtn", nullptr, "123456", nullptr, nullptr, "sip.linphone.org");
    linphone_core_add_auth_info(the_core, auth);
    linphone_auth_info_destroy(auth);

    auto proxy_cfg = linphone_core_create_proxy_config(the_core);

    auto from = linphone_core_create_address(the_core, "sip:diepdtn@sip.linphone.org");
    linphone_address_set_transport(from, LinphoneTransportUdp);

    linphone_proxy_config_set_identity(proxy_cfg, "DiepDTN <sip:diepdtn@sip.linphone.org>"); /*set identity with user name and domain*/
    const char* server_addr = linphone_address_get_domain(from); /*extract domain address from identity*/
    linphone_proxy_config_set_server_addr(proxy_cfg, server_addr); /* we assume domain = proxy server address*/
    linphone_proxy_config_enable_register(proxy_cfg, true); /*activate registration for this proxy config*/
    linphone_address_destroy(from); /*release resource*/

    linphone_core_add_proxy_config(the_core,proxy_cfg); /*add proxy config to linphone core*/
    linphone_core_set_default_proxy(the_core,proxy_cfg); /*set to default proxy*/

    auto chat_room = linphone_core_get_chat_room_from_uri(the_core, "sip:syn15694@sip.linphone.org");
    linphone_chat_room_send_message(chat_room, "Hello world"); /*sending message*/

    while (true) {
        linphone_core_iterate(the_core);
        std::this_thread::sleep_for(std::chrono::milliseconds {50});
    }
//    linphone_chat_room_destroy(chat_room);
    linphone_core_destroy(the_core);

}
