/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>

#include <src/Scrift.hpp>
#include <src/Syntax/Locale.hpp>

slocale_t
FLocale::Set() {
    slocale_def_t lang;
    slocale_t locale;
	
    locale.language = STR(getenv("LANG"));
	
    if(locale.language == lang.locale_tr) {
        locale.header_help    = "Scrift Fonksiyonları ve Argümanları\n\n";
        locale.header_general = "[Genel]\n";
        locale.header_output  = "[Çıktı]\n";
        locale.header_execute = "[Yürüt]\n";
        locale.header_path    = "[Yol]\n";
	    
        locale.cmd_username   = "Kullanıcı adını göster.\n";
        locale.cmd_config     = "Scrift'i özelleştir.\n";
        locale.cmd_castle     = "Scrift'in içinde oynayabileceğiniz Castle oyunu.\n";
        locale.cmd_gitlink    = "GitHub linkini göster.\n";
        locale.cmd_welcome    = "Hoşgeldiniz mesajını göster.\n";
        locale.cmd_contr      = "Katkı sağlayanları göster.\n";
        locale.cmd_fscrift    = "<file>'ı yorumla.\n";
        locale.cmd_clearlog   = "FeLog'u temizle.\n";
        locale.cmd_history    = "Scrift geçmişini göster.\n";
        locale.cmd_rmvhistory = "Scrift geçmişini temizle.\n";
        locale.cmd_settings   = "Ayarları göster.\n";
        locale.cmd_rmvsttngs  = "Ayarları temizle.\n";
        locale.cmd_fetcheya   = "Sistem bilgisi aracını göster (fpm).\n";
        locale.cmd_version    = "Versiyonu ve lisansı göster.\n";
        locale.cmd_now        = "Zamanı göster.\n";
        locale.cmd_uptime     = "Çalışma zamanını göster.\n";
        locale.cmd_asciiart   = "ASCII sanatını göster.\n";
        locale.cmd_template   = "Dil şablonu ile oluştur\n"; 
        locale.cmd_felog      = "FeLog'u göster.\n";
        locale.cmd_calendar   = "Takvimi göster.\n";
        locale.cmd_edifor     = "Edifor'u aç.\n";
        locale.cmd_addtext    = "<file>'a yazı ekle.\n";
        locale.cmd_readtext   = "<file>'ı oku.\n";
        locale.cmd_ctxt       = "Dosya oluştur.\n";
        locale.cmd_pause      = "Scrift'i durdur.\n";
        locale.cmd_cls        = "Scrift'i kapat.\n";
        locale.cmd_clear      = "Scrift'in arabelleğini temizle.\n"; 
        locale.cmd_ip         = "Yerel IP adresini göster.\n";
        locale.cmd_incognito  = "Gizli moda geç (on - off)\n";
        locale.cmd_res        = "Çözünürlük boyutunu göster.\n";
        
        locale.cmd_echo       = "<arg> [$#environment]'i yazdır.\n";	
        locale.cmd_output     = "Girilen komutun çıktısını yazdırır\n";
        locale.cmd_title      = "Uçbirimin başlığını değiştir.\n";
        locale.cmd_emoji      = "Emoji yazdır (orn: :thinking_face:)\n\n";

        locale.cmd_scr        = "<argument>'i yürüt.\n";
        locale.cmd_fpm        = "Fegeya Paket Yöneticisini çalıştır.\n";
        locale.cmd_previous   = "Önceki komutu getir ve yürüt.\n\n";
        
        locale.dir_not_exist  = " : Bu dizin ortalıkta yok!\n";
    }

    return locale;
}
