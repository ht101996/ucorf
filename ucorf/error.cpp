#include "error.h"

namespace ucorf
{

const char* ucorf_error_category::name() const BOOST_SYSTEM_NOEXCEPT
{
    return "ucorf_error";
}

std::string ucorf_error_category::message(int v) const
{
    switch (v) {
        case (int)eUcorfErrorCode::ec_ok:
            return "ok";

        case (int)eUcorfErrorCode::ec_snd_timeout:
            return "send timeout";

        case (int)eUcorfErrorCode::ec_rcv_timeout:
            return "receive timeout";

        case (int)eUcorfErrorCode::ec_call_error:
            return "call error";

        case (int)eUcorfErrorCode::ec_parse_error:
            return "parse error";

        case (int)eUcorfErrorCode::ec_no_estab:
            return "not estab";

        case (int)eUcorfErrorCode::ec_unsupport_protocol:
            return "unsupport protocol";

        case (int)eUcorfErrorCode::ec_req_wnd_full:
            return "request window was full";

        case (int)eUcorfErrorCode::ec_logic_error:
            return "logic error";
    }

    return "";
}

const boost::system::error_category& GetUcorfErrorCategory()
{
    static ucorf_error_category obj;
    return obj;
}
boost_ec MakeUcorfErrorCode(eUcorfErrorCode code)
{
    return boost_ec((int)code, GetUcorfErrorCategory());
}
void ThrowError(eUcorfErrorCode code, const char* what)
{
    if (std::uncaught_exception()) return ;
    throw boost::system::system_error(MakeUcorfErrorCode(code), what);
}

} //namespace ucorf
