/*
 * Exeptions/RuntimeException.cpp
 *
 * Copyright 2024 KoreLib Developers. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the â€œSoftwareâ€), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Exceptions/RuntimeException.hpp"

#include "backward.hpp"

#include <ostream>
#include <stdexcept>
#include <string>

namespace Kore::Exceptions
{
    RuntimeException::RuntimeException(const std::string& message) :
        std::runtime_error(message)
    {
    }

    RuntimeException::RuntimeException(const char* message) :
        std::runtime_error(message)
    {
    }

    void RuntimeException::printStackTrace(std::ostream& stream)
    {
        backward::StackTrace stacktrace;
        stacktrace.load_here();

        backward::Printer printer;
        printer.print(stacktrace, stream);
    }

} // namespace Kore::Exceptions
