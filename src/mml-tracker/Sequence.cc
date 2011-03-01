#include <algorithm>

#include "Pattern.h"
#include "Sequence.h"

Sequence::Sequence(
  uint32_t _numTracks, const std::vector<QString>& _trackNames)
  : numTracks(_numTracks), trackNames(_trackNames) {
}

void Sequence::addNewPattern(uint32_t position) {
  Pattern* pattern = new Pattern(numTracks);
  patterns.insert(patterns.begin() + position, pattern);
}

void Sequence::removePattern(uint32_t position) {
  patterns.erase(patterns.begin() + position);
}

uint32_t Sequence::getNumPatterns() const {
  return patterns.size();
}

uint32_t Sequence::getNumTracks() const {
  return numTracks;
}

Pattern* Sequence::getPattern(uint32_t index) const {
  if (index >= patterns.size()) {
    return NULL;
  } else {
    return patterns[index];
  }
}

const QString& Sequence::getTrackName(uint32_t index) const {
  return trackNames[index];
}
