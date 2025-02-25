#include "plugin.h"

void handle_finalize(ethPluginFinalize_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;

    msg->uiType = ETH_UI_TYPE_GENERIC;

    switch (context->selectorIndex) {
        case CLAIM_REGULAR_ACCOUNT:
        case CLAIM_MULTI_SIGNATURE_ACCOUNT:
        case REWARD_ADD_UNUSED_REWARDS:
        case REWARD_FUND_STAKING_REWARDS:
            msg->numScreens = 3;
            break;
        case CLAIM_AIRDROP:
        case REWARD_CREATE_POSITION:
            msg->numScreens = 2;
            break;
        case REWARD_INIT_FAST_UNLOCK:
        case REWARD_CLAIM_REWARDS:
        case REWARD_PAUSE_UNLOCKING:
        case REWARD_RESUME_UNLOCKING:
        case REWARD_DELETE_POSITIONS:
            msg->numScreens = context->lisk.body.reward.lock_ids_len;
            break;
        case REWARD_INC_LOCKING_AMOUNT:
        case REWARD_EXTEND_DURATION:
            msg->numScreens = context->lisk.body.rewardIncLockingAmount.len * 2;
            break;
        case GOVERNOR_CAST_VOTE:
            msg->numScreens = 2;
            break;
        case GOVERNOR_CAST_VOTE_WITH_REASON:
            msg->numScreens = 3;
            break;
        case GOVERNOR_PROPOSE:
            msg->numScreens = context->lisk.body.governorPropose.value_len * 2;
            break;
        default:
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }
}
