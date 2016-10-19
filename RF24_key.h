
#ifndef __RF24_KEY_H__
#define __RF24_KEY_H__ 

#ifdef	__cplusplus
extern "C" {
#endif

void radio_init_key(void);
void radio_send_key(const uint8_t *report, uint8_t size);

#ifdef	__cplusplus
}
#endif

#endif // __RF24_KEY_H__

