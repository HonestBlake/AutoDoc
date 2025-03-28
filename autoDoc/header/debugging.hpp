// #file: debugging.hpp

#pragma once

#include "genorator.hpp" // package general header

namespace worTech::autoDoc::debugging{

    // #namepace: debugStates, variable namespace
    namespace debugStates{
        // set TRACING when macro defined 
        #ifdef WT_AUTODOC_DEBUG_TRACING
        constexpr bool TRACING = true;
        #else
        constexpr bool TRACING = false;
        #endif
        // set VERVOSE_TRACING when macro defined
        #ifdef WT_AUTODOC_DEBUG_VERVOSE_TRACING
        constexpr bool VERVOSE_TRACING = true;
        #else
        constexpr bool VERVOSE_TRACING = false;
        #endif
        // set WARNING_IS_ERROR when macro defined
        #ifdef WT_AUTODOC_DEBUG_WARNING_IS_ERROR
        constexpr bool WARNING_IS_ERROR = true;
        #else
        constexpr bool WARNING_IS_ERROR = false;
        #endif
    }
    // #namespace: errorMessages, variable namespace
    namespace errorMessages{
        const std::string NO_COMMAND_LINE_ARGUMENTS = "No command line arguments provided";
        const std::string UNRECONIZED_COMMAND_LINE_ARGUMENT = "Unreconized command line argument: {}";
        const std::string UNRECONIZED_DOC_PACKET = "Unreconized doc packet: {}";
        const std::string INVALID_CONFIG_FILE_TYPE = "Provided config file is not a valid {} file: {}";
        const std::string COULD_NOT_FIND_CONFIG_FILE = "Could not locate config file: {}";
        const std::string COULD_NOT_FIND_OUTPUT_DIRECTORY = "Could not locate output directory: {}";
        const std::string OUTPUT_DIRECTORY_IS_NOT_DIRECTORY = "Provided output directory is not a directory: {}";
        const std::string INVALID_SOURCE_FILE_TYPE = "Provided source file is not a valid file type from given doc packets: {}";
        const std::string COULD_NOT_FIND_SOURCE = "Could not locate source: {}";
        const std::string COULD_NOT_FIND_IGNORE = "Could not locate ignore: {}";
    }
    // #namespace: debugTools, function namespace
    namespace debugTools{
        template<typename... T_args> void warn(const std::string& p_warning, T_args... p_args)noexcept;
        template<typename... T_args> void error(const std::string& p_error, T_args... p_args)noexcept;
        void trace(std::source_location&& p_location)noexcept;
    }
    // #namespace: loggerValues, variable namespace
    namespace loggerValues{
        const std::string TRACER_NAME = "AutoDoc Tracer";
        const std::string DEBUG_NAME = "AutoDoc Debug";
        const std::array<btr::Format, 5> TRACER_FORMAT = {
            btr::Format::LOGGER, 
            btr::Format::LEVEL, 
            btr::Format::LOCATION, 
            btr::Format::TIME, 
            btr::Format::MESSAGE
        };
    }
    // #class: AutoDocTracer, singleton class 
    class AutoDocTracer: public btr::Logger{
    public:
        AutoDocTracer();
    private:
        std::string formatLocation(const btr::Level p_logLevel, const std::source_location& p_location)const override;
    };
    // #class: AutoDocError, singleton class
    class AutoDocDebug: public btr::Logger{
    public: 
        AutoDocDebug();
    private:
        const Logger& sendLog(std::string&& p_log)const override;
    };

} // namespace worTech::autoDoc::debugging
