/*# MIT License
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef EMOJI_PLUS_PLUS_H
#define EMOJI_PLUS_PLUS_H

#include <map>

namespace emojiplusplus {

    static std::map<std::string, std::string> EMOJIS = {
        {":admission_tickets:" , "\U0001F39F"},
        {":aerial_tramway:" , "\U0001F6A1"},
        {":airplane:" , "\U00002708"},
        {":airplane_arriving:" , "\U0001F6EC"},
        {":airplane_departure:" , "\U0001F6EB"},
        {":alarm_clock:" , "\U000023F0"},
        {":alembic:" , "\U00002697"},
        {":space_invader:" , "\U0001F47E"},
        {":ambulance:" , "\U0001F691"},
        {":football:" , "\U0001F3C8"},
        {":amphora:" , "\U0001F3FA"},
        {":anchor:" , "\U00002693"},
        {":anger:" , "\U0001F4A2"},
        {":angry:" , "\U0001F620"},
        {":anguished:" , "\U0001F627"},
        {":ant:" , "\U0001F41C"},
        {":signal_strength:" , "\U0001F4F6"},
        {":arrows_counterclockwise:" , "\U0001F504"},
        {":aquarius:" , "\U00002652"},
        {":aries:" , "\U00002648"},
        {":arrow_heading_down:" , "\U00002935"},
        {":arrow_heading_up:" , "\U00002934"},
        {":articulated_lorry:" , "\U0001F69B"},
        {":art:" , "\U0001F3A8"},
        {":astonished:" , "\U0001F632"},
        {":athletic_shoe:" , "\U0001F45F"},
        {":atom_symbol:" , "\U0000269B"},
        {":eggplant:" , "\U0001F346"},
        {":atm:" , "\U0001F3E7"},
        {":car:" , "\U0001F697"},
        {":smile:" , "\U0001F604"},
        {":zipper__mouth_face:" , "\U0001F910"}
    };  

    std::string EmojiString(std::string s) {
        int index = -1;
        int sLen = s.size();
        for (int i = 0; i < sLen; i++) {
            if (s[i] == *L":") {
                if (index == -1) {
                    index = i;
                }
                else {
                    if (i - index==1) {
                        index = i;
                        continue;
                    }
                    std::map<std::string, std::string>::iterator it;
                    it = EMOJIS.find(s.substr(index, i - index + 1));
                    if (it == EMOJIS.end()) {
                        index = i;
                        continue;
                    }
                    std::string emo = it->second;
                    s.replace(index, i - index + 1 , emo);
                    int goBack = i - index + 1 - emo.size();
                    sLen -= goBack;
                    i -= goBack;
                    index = -1;
                }
            }
        }
        return s;
    }
}

#endif // EMOJI_PLUS_PLUS_H
