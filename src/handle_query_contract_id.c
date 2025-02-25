#include "plugin.h"

// Sets the first screen to display.
void handle_query_contract_id(ethQueryContractID_t *msg) {
    const context_t *context = (const context_t *) msg->pluginContext;
    // msg->name will be the upper sentence displayed on the screen.
    // msg->version will be the lower sentence displayed on the screen.

    // For the first screen, display the plugin name.
    strlcpy(msg->name, APPNAME, msg->nameLength);

    // EDIT THIS: Adapt the cases by modifying the strings you pass to `strlcpy`.
    if (context->selectorIndex == CLAIM_REGULAR_ACCOUNT ||
        context->selectorIndex == CLAIM_MULTI_SIGNATURE_ACCOUNT) {
        strlcpy(msg->version, "Claim LSK", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_CREATE_POSITION) {
        strlcpy(msg->version, "Stake Amount", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_INIT_FAST_UNLOCK) {
        strlcpy(msg->version, "Fast Unlock", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_CLAIM_REWARDS) {
        strlcpy(msg->version, "Claim Rewards", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_PAUSE_UNLOCKING) {
        strlcpy(msg->version, "Pause Unlocking", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_RESUME_UNLOCKING) {
        strlcpy(msg->version, "Resume Unlocking", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_INC_LOCKING_AMOUNT) {
        strlcpy(msg->version, "Inc Locking Amount", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_EXTEND_DURATION) {
        strlcpy(msg->version, "Extend Duration", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_DELETE_POSITIONS) {
        strlcpy(msg->version, "Delete Positions", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_ADD_UNUSED_REWARDS) {
        strlcpy(msg->version, "Add Unused Rewards", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == REWARD_FUND_STAKING_REWARDS) {
        strlcpy(msg->version, "Fund Staking Rewards", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == CLAIM_AIRDROP) {
        strlcpy(msg->version, "Claim Airdrop", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == GOVERNOR_CAST_VOTE ||
               context->selectorIndex == GOVERNOR_CAST_VOTE_WITH_REASON) {
        strlcpy(msg->version, "Cast Vote", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else if (context->selectorIndex == GOVERNOR_PROPOSE) {
        strlcpy(msg->version, "Propose", msg->versionLength);
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else {
        PRINTF("Selector index: %d not supported\n", context->selectorIndex);
        msg->result = ETH_PLUGIN_RESULT_ERROR;
    }
}
