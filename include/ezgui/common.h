#if __STDC__ != 1
#    warning not conforming
#    if !defined(restrict)
#        define restrict __restrict /* use implementation __ format */
#    endif
#else
#    ifndef __STDC_VERSION__
#        warning not conforming
#        if !defined(restrict)
#            define restrict __restrict /* use implementation __ format */
#        endif
#    else
#        if __STDC_VERSION__ < 199901L
#            warning Compiler for C before C99
#            if !defined(restrict)
#                define restrict __restrict /* use implementation __ format */
#            endif
#        else

#        endif
#    endif
#endif