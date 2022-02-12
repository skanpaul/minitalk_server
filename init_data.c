

#include "server.h"

/* ************************************************************************** */
void init_data(t_data *data)
{
    /* Configuration STRUCT SIGACTION ---------------- */
	data->sa.sa_handler = &handler_sig_usr;
	data->sa.sa_flags = SA_RESTART;
    // sigaddset(&data->sa.sa_mask, SIGUSR1);
    // sigaddset(&data->sa.sa_mask, SIGUSR2);

    /* Configuration BYTE ET BIT --------------------- */
    data->mask = MASK_BIT_7;
    data->byte = 0;
    data->bit_cnt = 0;
    data->byte_cnt = 0;
    /* ----------------------------------------------- */
}
