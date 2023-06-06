#include <fs_handles_db.h>
#include <mtp.h>
#include <stdio.h>

static inline void tvt_log_fs_access(char * type, mtp_ctx * ctx, struct fs_entry * entry) {

    // Open the log file
    FILE * log_file = fopen("/mtp_ops.log", "a");
    if(log_file == NULL) {
        printf("Could not open log file\n");
        return;
    }

    fprintf(log_file, "The type of action is %s\n", type);
    // Check if the entry is not null
    if(entry == NULL) {
        fprintf(log_file,"fs_entry is NULL!!!!!\n");
        fclose(log_file);
        return;
    }

    fprintf(log_file, "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    fprintf(log_file, "Storage root: %s\n", mtp_get_storage_root(ctx, entry->storage_id));

    // Print the entry fields to the log file
    fprintf(log_file, "handle: %u\n", entry->handle);
    fprintf(log_file, "parent: %u\n", entry->parent);
    fprintf(log_file, "storage_id: %u\n", entry->storage_id);
    fprintf(log_file, "name: %s\n", entry->name ? entry->name : "NULL");
    fprintf(log_file, "flags: %u\n", entry->flags);
    fprintf(log_file, "size: %llu\n", (unsigned long long)entry->size);
    fprintf(log_file, "date: %u\n", entry->date);
    fprintf(log_file, "watch_descriptor: %d\n", entry->watch_descriptor);
    fprintf(log_file, "next: %p\n", (void *)entry->next);
    fprintf(log_file, "-----------------------------------------------------------------\n\n");
    // Close the log file
    fflush(log_file);
    fclose(log_file);
}
