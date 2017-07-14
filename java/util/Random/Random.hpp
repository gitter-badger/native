/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NATIVE_JAVA_UTIL_RANDOM_HPP
#define NATIVE_JAVA_UTIL_RANDOM_HPP

#include <atomic>
#include "random"
#include "../../Lang.hpp"

namespace Java {
    namespace Util {
        class Random{

        protected:
            std::atomic_long seed{0};
            std::atomic_long seedUniquifierField{8682522807148012L};
            static const long multiplier = 0x5DEECE66DL;
            static const long addend = 0xBL;
            static constexpr long mask = (1L << 48) - 1;
            static constexpr double DOUBLE_UNIT = 0x1.0p-53; // 1.0 / (1L << 53)
            boolean haveNextGaussian = false;
            double nextNextGaussian;
            static long seedOffset;

        public:
            // IllegalArgumentException messages
            const String BadBound = "bound must be positive";
            const String BadRange = "bound must be greater than origin";
            const String BadSize  = "size must be non-negative";

        protected:
            long initialScramble(long seed);

            //void readObject(ObjectInputStream s);

            void resetSeed(long seedVal);

            long seedUniquifier();

            //void writeObject(ObjectOutputStream s)

            long nanoTime();

        protected:
            int next(int bits);

        public:
            Random();

            Random(long seed);

            //DoubleStream doubles();

            //DoubleStream doubles(long streamSize);

            //DoubleStream doubles(double randomNumberOrigin, double randomNumberBound);

            //DoubleStream doubles(long streamSize, double randomNumberOrigin,double randomNumberBound);

            double internalNextDouble(double origin, double bound);

            int internalNextInt(int origin, int bound);

            long internalNextLong(long origin, long bound);

            //IntStream ints();

            //IntStream ints(long streamSize);

            //IntStream ints(int randomNumberOrigin, int randomNumberBound);

            //IntStream ints(long streamSize, int randomNumberOrigin, int randomNumberBound);

            //LongStream longs();

            //LongStream longs(long streamSize);

            //LongStream longs(long randomNumberOrigin, long randomNumberBound);

            //LongStream longs(long streamSize, long randomNumberOrigin, long randomNumberBound);

            boolean nextBoolean();

            void nextBytes(byte bytes[]);

            double nextDouble();

            float nextFloat();

            double nextGaussian();

            int nextInt();

            int nextInt(int bound);

            long nextLong();

            void setSeed(long seed);

            //For test
            long getSeed(){
                return (long) seed.load();
            }
        };
    }
}

#endif