// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/html/custom/V0CustomElementSyncMicrotaskQueue.h"

namespace blink {

void V0CustomElementSyncMicrotaskQueue::Enqueue(
    V0CustomElementMicrotaskStep* step) {
  queue_.push_back(step);
}

void V0CustomElementSyncMicrotaskQueue::DoDispatch() {
  unsigned i;

  for (i = 0; i < queue_.size(); ++i) {
    if (V0CustomElementMicrotaskStep::kProcessing == queue_[i]->Process())
      break;
  }

  queue_.erase(0, i);
}

}  // namespace blink
