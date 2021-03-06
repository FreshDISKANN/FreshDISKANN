#pragma once
#ifdef _WINDOWS
#ifdef USE_BING_INFRA
#include "dll/IDiskPriorityIO.h"
#include "aligned_file_reader.h"

namespace diskann {
  class BingAlignedFileReader : public AlignedFileReader {
   private:
    std::string                                m_filename;
    std::shared_ptr<ANNIndex::IDiskPriorityIO> m_pDiskPriorityIO;

   public:
    DISKANN_DLLEXPORT BingAlignedFileReader(
        std::shared_ptr<ANNIndex::IDiskPriorityIO> pDiskIO = nullptr);
    DISKANN_DLLEXPORT virtual ~BingAlignedFileReader();

    virtual void register_thread();
    virtual void deregister_thread();

    virtual IOContext &get_ctx();

    // Open & close ops
    // Blocking calls
    virtual void open(const std::string &fname, bool enable_writes,
                      bool enable_create);
    virtual void close();

    // process batch of aligned requests in parallel
    // NOTE :: blocking call for the calling thread, but can thread-safe
    virtual void read(std::vector<AlignedRead> &read_reqs, IOContext &ctx,
                      bool async = false);
  };
}  // namespace NSG
#endif
#endif
