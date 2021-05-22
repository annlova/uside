#ifndef __uside_glad23_h_
#define __uside_glad23_h_
#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
GLAPI int GLAD_GL_VERSION_1_4;
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glBlendFuncSeparate'>OpenGL 4</a><br /><a  href='../gl3/glBlendFuncSeparate'>OpenGL 3</a><br /><a  href='../gl2/glBlendFuncSeparate'>OpenGL 2</a><br /><a  href='../es3/glBlendFuncSeparate'>OpenGL ES 3</a><br /><a  href='../es2/glBlendFuncSeparate'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glBlendFuncSeparate</h1>
    <div class="refentry" id="glBlendFuncSeparate">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glBlendFuncSeparate — specify pixel arithmetic for RGB and alpha components separately</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glBlendFuncSeparate</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">srcRGB</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">dstRGB</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">srcAlpha</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">dstAlpha</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glBlendFuncSeparatei</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">buf</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">srcRGB</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">dstRGB</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">srcAlpha</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">dstAlpha</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>buf</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glBlendFuncSeparatei</code>, specifies the index of the draw
                    buffer for which to set the blend functions.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>srcRGB</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies how the red, green, and blue blending factors are computed.
                    The initial value is <code class="constant">GL_ONE</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>dstRGB</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies how the red, green, and blue destination blending factors are
                    computed.
                    The initial value is <code class="constant">GL_ZERO</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>srcAlpha</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specified how the alpha source blending factor is computed.
                    The initial value is <code class="constant">GL_ONE</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>dstAlpha</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specified how the alpha destination blending factor is computed.
                    The initial value is <code class="constant">GL_ZERO</code>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Pixels can be drawn using a function that blends
            the incoming (source) RGBA values with the RGBA values
            that are already in the frame buffer (the destination values).
            Blending is initially disabled.
            Use <a class="citerefentry" href="glEnable"><span class="citerefentry"><span class="refentrytitle">glEnable</span></span></a> and <a class="citerefentry" href="glDisable"><span class="citerefentry"><span class="refentrytitle">glDisable</span></span></a> with argument <code class="constant">GL_BLEND</code>
            to enable and disable blending.
        </p>
        <p>
            <code class="function">glBlendFuncSeparate</code> defines the operation of blending for all draw buffers when it is enabled.
            <code class="function">glBlendFuncSeparatei</code> defines the operation of blending for a single draw buffer
            specified by <em class="parameter"><code>buf</code></em> when enabled for that draw buffer.
            <em class="parameter"><code>srcRGB</code></em> specifies which method is used to scale the
            source RGB-color components.
            <em class="parameter"><code>dstRGB</code></em> specifies which method is used to scale the
            destination RGB-color components.
            Likewise, <em class="parameter"><code>srcAlpha</code></em> specifies which method is used to scale the source alpha
            color component, and <em class="parameter"><code>dstAlpha</code></em> specifies which method is used to scale the
            destination alpha component.
            The possible methods are described in the following table.
            Each method defines four scale factors,
            one each for red, green, blue, and alpha.
        </p>
        <p>
            In the table and in subsequent equations, first source, second source and destination
            color components are referred to as
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">s0</mi>
                    </msub>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">s0</mi>
                    </msub>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">s0</mi>
                    </msub>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">s0</mi>
                    </msub>
                </mfenced>
            </math>,
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">s1</mi>
                    </msub>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">s1</mi>
                    </msub>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">s1</mi>
                    </msub>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">s1</mi>
                    </msub>
                </mfenced>
            </math>,
            and
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                </mfenced>
            </math>, respectively.
            The color specified by <a class="citerefentry" href="glBlendColor"><span class="citerefentry"><span class="refentrytitle">glBlendColor</span></span></a> is referred to as
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">c</mi>
                    </msub>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">c</mi>
                    </msub>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">c</mi>
                    </msub>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">c</mi>
                    </msub>
                </mfenced>
            </math>.
            They are understood to have integer values between 0 and
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">k</mi>
                    <mi mathvariant="italic">R</mi>
                    </msub>
                    <msub><mi mathvariant="italic">k</mi>
                    <mi mathvariant="italic">G</mi>
                    </msub>
                    <msub><mi mathvariant="italic">k</mi>
                    <mi mathvariant="italic">B</mi>
                    </msub>
                    <msub><mi mathvariant="italic">k</mi>
                    <mi mathvariant="italic">A</mi>
                    </msub>
                </mfenced>
            </math>,
            where
        </p>
        <p>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">k</mi>
                    <mi mathvariant="italic">c</mi>
                    </msub>
                    <mo>=</mo>
                    <mrow>
                        <msup><mn>2</mn>
                        <mfenced open="" close="">
                            <msub><mi mathvariant="italic">m</mi>
                            <mi mathvariant="italic">c</mi>
                            </msub>
                        </mfenced>
                        </msup>
                        <mo>-</mo>
                        <mn>1</mn>
                    </mrow>
                </mrow>
            </math>
        </p>
        <p>
            and
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">m</mi>
                    <mi mathvariant="italic">R</mi>
                    </msub>
                    <msub><mi mathvariant="italic">m</mi>
                    <mi mathvariant="italic">G</mi>
                    </msub>
                    <msub><mi mathvariant="italic">m</mi>
                    <mi mathvariant="italic">B</mi>
                    </msub>
                    <msub><mi mathvariant="italic">m</mi>
                    <mi mathvariant="italic">A</mi>
                    </msub>
                </mfenced>
            </math>
            is the number of red,
            green,
            blue,
            and alpha bitplanes.
        </p>
        <p>
            Source and destination scale factors are referred to as
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">s</mi>
                    <mi mathvariant="italic">R</mi>
                    </msub>
                    <msub><mi mathvariant="italic">s</mi>
                    <mi mathvariant="italic">G</mi>
                    </msub>
                    <msub><mi mathvariant="italic">s</mi>
                    <mi mathvariant="italic">B</mi>
                    </msub>
                    <msub><mi mathvariant="italic">s</mi>
                    <mi mathvariant="italic">A</mi>
                    </msub>
                </mfenced>
            </math>
            and
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">d</mi>
                    <mi mathvariant="italic">R</mi>
                    </msub>
                    <msub><mi mathvariant="italic">d</mi>
                    <mi mathvariant="italic">G</mi>
                    </msub>
                    <msub><mi mathvariant="italic">d</mi>
                    <mi mathvariant="italic">B</mi>
                    </msub>
                    <msub><mi mathvariant="italic">d</mi>
                    <mi mathvariant="italic">A</mi>
                    </msub>
                </mfenced>
            </math>.
            All scale factors have range
            <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mn>0</mn>
                    <mn>1</mn>
                </mfenced>
            </math>.
        </p>
        <p>
        </p>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: left; "/>
              <col style="text-align: left; "/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <span class="bold"><strong> Parameter </strong></span>
                        </th>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <span class="bold"><strong> RGB Factor </strong></span>
                        </th>
                <th style="text-align: left; border-bottom: 2px solid ; ">
                            <span class="bold"><strong> Alpha Factor </strong></span>
                        </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ZERO</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mn>0</mn>
                                <mn>0</mn>
                                <mn>0</mn>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mn>0</mn>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ONE</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mn>1</mn>
                                <mn>1</mn>
                                <mn>1</mn>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mn>1</mn>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_SRC_COLOR</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mfrac>
                                    <msub><mi mathvariant="italic">R</mi>
                                    <mi mathvariant="italic">s0</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">R</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">G</mi>
                                    <mi mathvariant="italic">s0</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">G</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">B</mi>
                                    <mi mathvariant="italic">s0</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">B</mi>
                                    </msub>
                                </mfrac>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfrac>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">s0</mi>
                                </msub>
                                <msub><mi mathvariant="italic">k</mi>
                                <mi mathvariant="italic">A</mi>
                                </msub>
                            </mfrac>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ONE_MINUS_SRC_COLOR</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mfenced open="(" close=")">
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                </mfenced>
                                <mo>-</mo>
                                <mfenced open="(" close=")">
                                    <mfrac>
                                        <msub><mi mathvariant="italic">R</mi>
                                        <mi mathvariant="italic">s0</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">R</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">G</mi>
                                        <mi mathvariant="italic">s0</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">G</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">B</mi>
                                        <mi mathvariant="italic">s0</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">B</mi>
                                        </msub>
                                    </mfrac>
                                </mfenced>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s0</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_DST_COLOR</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mfrac>
                                    <msub><mi mathvariant="italic">R</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">R</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">G</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">G</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">B</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">B</mi>
                                    </msub>
                                </mfrac>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfrac>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">d</mi>
                                </msub>
                                <msub><mi mathvariant="italic">k</mi>
                                <mi mathvariant="italic">A</mi>
                                </msub>
                            </mfrac>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ONE_MINUS_DST_COLOR</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mfenced open="(" close=")">
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                </mfenced>
                                <mo>-</mo>
                                <mfenced open="(" close=")">
                                    <mfrac>
                                        <msub><mi mathvariant="italic">R</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">R</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">G</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">G</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">B</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">B</mi>
                                        </msub>
                                    </mfrac>
                                </mfenced>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_SRC_ALPHA</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s0</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s0</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s0</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfrac>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">s0</mi>
                                </msub>
                                <msub><mi mathvariant="italic">k</mi>
                                <mi mathvariant="italic">A</mi>
                                </msub>
                            </mfrac>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ONE_MINUS_SRC_ALPHA</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mfenced open="(" close=")">
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                </mfenced>
                                <mo>-</mo>
                                <mfenced open="(" close=")">
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">s0</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">s0</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">s0</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                </mfenced>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s0</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_DST_ALPHA</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfrac>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">d</mi>
                                </msub>
                                <msub><mi mathvariant="italic">k</mi>
                                <mi mathvariant="italic">A</mi>
                                </msub>
                            </mfrac>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ONE_MINUS_DST_ALPHA</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mfenced open="(" close=")">
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                </mfenced>
                                <mo>-</mo>
                                <mfenced open="(" close=")">
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                </mfenced>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_CONSTANT_COLOR</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <msub><mi mathvariant="italic">R</mi>
                                <mi mathvariant="italic">c</mi>
                                </msub>
                                <msub><mi mathvariant="italic">G</mi>
                                <mi mathvariant="italic">c</mi>
                                </msub>
                                <msub><mi mathvariant="italic">B</mi>
                                <mi mathvariant="italic">c</mi>
                                </msub>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <msub><mi mathvariant="italic">A</mi>
                            <mi mathvariant="italic">c</mi>
                            </msub>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ONE_MINUS_CONSTANT_COLOR</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mfenced open="(" close=")">
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                </mfenced>
                                <mo>-</mo>
                                <mfenced open="(" close=")">
                                    <msub><mi mathvariant="italic">R</mi>
                                    <mi mathvariant="italic">c</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">G</mi>
                                    <mi mathvariant="italic">c</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">B</mi>
                                    <mi mathvariant="italic">c</mi>
                                    </msub>
                                </mfenced>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">c</mi>
                                </msub>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_CONSTANT_ALPHA</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">c</mi>
                                </msub>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">c</mi>
                                </msub>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">c</mi>
                                </msub>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <msub><mi mathvariant="italic">A</mi>
                            <mi mathvariant="italic">c</mi>
                            </msub>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ONE_MINUS_CONSTANT_ALPHA</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mfenced open="(" close=")">
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                </mfenced>
                                <mo>-</mo>
                                <mfenced open="(" close=")">
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">c</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">c</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">c</mi>
                                    </msub>
                                </mfenced>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">c</mi>
                                </msub>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_SRC_ALPHA_SATURATE</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mi mathvariant="italic">i</mi>
                                <mi mathvariant="italic">i</mi>
                                <mi mathvariant="italic">i</mi>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mn>1</mn>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_SRC1_COLOR</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mfrac>
                                    <msub><mi mathvariant="italic">R</mi>
                                    <mi mathvariant="italic">s1</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">R</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">G</mi>
                                    <mi mathvariant="italic">s1</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">G</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">B</mi>
                                    <mi mathvariant="italic">s1</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">B</mi>
                                    </msub>
                                </mfrac>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfrac>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">s1</mi>
                                </msub>
                                <msub><mi mathvariant="italic">k</mi>
                                <mi mathvariant="italic">A</mi>
                                </msub>
                            </mfrac>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_ONE_MINUS_SRC_COLOR</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mfenced open="(" close=")">
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                </mfenced>
                                <mo>-</mo>
                                <mfenced open="(" close=")">
                                    <mfrac>
                                        <msub><mi mathvariant="italic">R</mi>
                                        <mi mathvariant="italic">s1</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">R</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">G</mi>
                                        <mi mathvariant="italic">s1</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">G</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">B</mi>
                                        <mi mathvariant="italic">s1</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">B</mi>
                                        </msub>
                                    </mfrac>
                                </mfenced>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s1</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "> <code class="constant">GL_SRC1_ALPHA</code> </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfenced open="(" close=")">
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s1</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s1</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s1</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mfenced>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mfrac>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">s1</mi>
                                </msub>
                                <msub><mi mathvariant="italic">k</mi>
                                <mi mathvariant="italic">A</mi>
                                </msub>
                            </mfrac>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; "> <code class="constant">GL_ONE_MINUS_SRC_ALPHA</code> </td>
                <td style="text-align: left; border-right: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mfenced open="(" close=")">
                                    <mn>1</mn>
                                    <mn>1</mn>
                                    <mn>1</mn>
                                </mfenced>
                                <mo>-</mo>
                                <mfenced open="(" close=")">
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">s1</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">s1</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                    <mfrac>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">s1</mi>
                                        </msub>
                                        <msub><mi mathvariant="italic">k</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mfrac>
                                </mfenced>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; ">
                        <math overflow="scroll">

                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <mfrac>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s1</mi>
                                    </msub>
                                    <msub><mi mathvariant="italic">k</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mfrac>
                            </mrow>
                        </math>
                        </td>
              </tr>
            </tbody>
          </table>
        </div>
        <p>
            In the table,
        </p>
        <p>
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">i</mi>
                    <mo>=</mo>
                    <mrow>
                        <mi mathvariant="italic">min</mi>
                        <mo>⁡</mo>
                        <mfenced open="(" close=")">
                            <msub><mi mathvariant="italic">A</mi>
                            <mi mathvariant="italic">s</mi>
                            </msub>
                            <mrow>
                                <mn>1</mn>
                                <mo>-</mo>
                                <mfenced open="" close="">
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                </mfenced>
                            </mrow>
                        </mfenced>
                    </mrow>
                </mrow>
            </math>
        </p>
        <p>
            To determine the blended RGBA values of a pixel,
            the system uses the following equations:
        </p>
        <p>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <mo>=</mo>
                    <mrow>
                        <mi mathvariant="italic">min</mi>
                        <mo>⁡</mo>
                        <mfenced open="(" close=")">
                            <msub><mi mathvariant="italic">k</mi>
                            <mi mathvariant="italic">R</mi>
                            </msub>
                            <mrow>
                                <msub><mi mathvariant="italic">R</mi>
                                <mi mathvariant="italic">s</mi>
                                </msub>
                                <mo>⁢</mo>
                                <msub><mi mathvariant="italic">s</mi>
                                <mi mathvariant="italic">R</mi>
                                </msub>
                                <mo>+</mo>
                                <msub><mi mathvariant="italic">R</mi>
                                <mi mathvariant="italic">d</mi>
                                </msub>
                                <mo>⁢</mo>
                                <msub><mi mathvariant="italic">d</mi>
                                <mi mathvariant="italic">R</mi>
                                </msub>
                            </mrow>
                        </mfenced>
                    </mrow>
                </mrow>
            </math>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <mo>=</mo>
                    <mrow>
                        <mi mathvariant="italic">min</mi>
                        <mo>⁡</mo>
                        <mfenced open="(" close=")">
                            <msub><mi mathvariant="italic">k</mi>
                            <mi mathvariant="italic">G</mi>
                            </msub>
                            <mrow>
                                <msub><mi mathvariant="italic">G</mi>
                                <mi mathvariant="italic">s</mi>
                                </msub>
                                <mo>⁢</mo>
                                <msub><mi mathvariant="italic">s</mi>
                                <mi mathvariant="italic">G</mi>
                                </msub>
                                <mo>+</mo>
                                <msub><mi mathvariant="italic">G</mi>
                                <mi mathvariant="italic">d</mi>
                                </msub>
                                <mo>⁢</mo>
                                <msub><mi mathvariant="italic">d</mi>
                                <mi mathvariant="italic">G</mi>
                                </msub>
                            </mrow>
                        </mfenced>
                    </mrow>
                </mrow>
            </math>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <mo>=</mo>
                    <mrow>
                        <mi mathvariant="italic">min</mi>
                        <mo>⁡</mo>
                        <mfenced open="(" close=")">
                            <msub><mi mathvariant="italic">k</mi>
                            <mi mathvariant="italic">B</mi>
                            </msub>
                            <mrow>
                                <msub><mi mathvariant="italic">B</mi>
                                <mi mathvariant="italic">s</mi>
                                </msub>
                                <mo>⁢</mo>
                                <msub><mi mathvariant="italic">s</mi>
                                <mi mathvariant="italic">B</mi>
                                </msub>
                                <mo>+</mo>
                                <msub><mi mathvariant="italic">B</mi>
                                <mi mathvariant="italic">d</mi>
                                </msub>
                                <mo>⁢</mo>
                                <msub><mi mathvariant="italic">d</mi>
                                <mi mathvariant="italic">B</mi>
                                </msub>
                            </mrow>
                        </mfenced>
                    </mrow>
                </mrow>
            </math>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <mo>=</mo>
                    <mrow>
                        <mi mathvariant="italic">min</mi>
                        <mo>⁡</mo>
                        <mfenced open="(" close=")">
                            <msub><mi mathvariant="italic">k</mi>
                            <mi mathvariant="italic">A</mi>
                            </msub>
                            <mrow>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">s</mi>
                                </msub>
                                <mo>⁢</mo>
                                <msub><mi mathvariant="italic">s</mi>
                                <mi mathvariant="italic">A</mi>
                                </msub>
                                <mo>+</mo>
                                <msub><mi mathvariant="italic">A</mi>
                                <mi mathvariant="italic">d</mi>
                                </msub>
                                <mo>⁢</mo>
                                <msub><mi mathvariant="italic">d</mi>
                                <mi mathvariant="italic">A</mi>
                                </msub>
                            </mrow>
                        </mfenced>
                    </mrow>
                </mrow>
            </math>
        </p>
        <p>
            Despite the apparent precision of the above equations, blending arithmetic
            is not exactly specified, because blending operates with imprecise integer
            color values.  However, a blend factor that should be equal to 1 is
            guaranteed not to modify its multiplicand, and a blend factor equal to 0
            reduces its multiplicand to 0.  For example, when <em class="parameter"><code>srcRGB</code></em> is
            <code class="constant">GL_SRC_ALPHA</code>, <em class="parameter"><code>dstRGB</code></em> is <code class="constant">GL_ONE_MINUS_SRC_ALPHA</code>, and
            <math overflow="scroll">

                <msub><mi mathvariant="italic">A</mi>
                <mi mathvariant="italic">s</mi>
                </msub>
            </math>
            is
            equal to
            <math overflow="scroll">

                <msub><mi mathvariant="italic">k</mi>
                <mi mathvariant="italic">A</mi>
                </msub>
            </math>,
            the equations reduce to simple replacement:
        </p>
        <p>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <mo>=</mo>
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
                </mrow>
            </math>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <mo>=</mo>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
                </mrow>
            </math>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <mo>=</mo>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
                </mrow>
            </math>
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <mo>=</mo>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
                </mrow>
            </math>
        </p>
        <p>
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            Incoming (source) alpha is correctly thought of as a material opacity,
            ranging from 1.0
            (<math overflow="scroll">

                <msub><mi mathvariant="italic">K</mi>
                <mi mathvariant="italic">A</mi>
                </msub>
            </math>),
            representing complete opacity,
            to 0.0 (0), representing complete
            transparency.
        </p>
        <p>
            When more than one color buffer is enabled for drawing,
            the GL performs blending separately for each enabled buffer,
            using the contents of that buffer for destination color.
            (See <a class="citerefentry" href="glDrawBuffer"><span class="citerefentry"><span class="refentrytitle">glDrawBuffer</span></span></a>.)
        </p>
        <p>
            When dual source blending is enabled (i.e., one of the blend factors requiring
            the second color input is used), the maximum number of enabled draw buffers
            is given by <code class="constant">GL_MAX_DUAL_SOURCE_DRAW_BUFFERS</code>, which may
            be lower than <code class="constant">GL_MAX_DRAW_BUFFERS</code>.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if either <em class="parameter"><code>srcRGB</code></em> or <em class="parameter"><code>dstRGB</code></em> is not an
            accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated by <code class="function">glBlendFuncSeparatei</code> if <em class="parameter"><code>buf</code></em> is greater
            than or equal to the value of <code class="constant">GL_MAX_DRAW_BUFFERS</code>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_BLEND_SRC_RGB</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_BLEND_SRC_ALPHA</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_BLEND_DST_RGB</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_BLEND_DST_ALPHA</code>
        </p>
        <p>
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a> with argument <code class="constant">GL_BLEND</code>
        </p>
        <p>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glBlendFuncSeparate</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glBlendFuncSeparatei</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glBlendColor"><span class="citerefentry"><span class="refentrytitle">glBlendColor</span></span></a>,
            <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a>,
            <a class="citerefentry" href="glBlendEquation"><span class="citerefentry"><span class="refentrytitle">glBlendEquation</span></span></a>,
            <a class="citerefentry" href="glClear"><span class="citerefentry"><span class="refentrytitle">glClear</span></span></a>,
            <a class="citerefentry" href="glDrawBuffer"><span class="citerefentry"><span class="refentrytitle">glDrawBuffer</span></span></a>,
            <a class="citerefentry" href="glEnable"><span class="citerefentry"><span class="refentrytitle">glEnable</span></span></a>,
            <a class="citerefentry" href="glLogicOp"><span class="citerefentry"><span class="refentrytitle">glLogicOp</span></span></a>,
            <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glBlendFuncSeparate.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glBlendFuncSeparate glad_glBlendFuncSeparate
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLAPI PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glMultiDrawArrays'>OpenGL 4</a><br /><a  href='../gl3/glMultiDrawArrays'>OpenGL 3</a><br /><a  href='../gl2/glMultiDrawArrays'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glMultiDrawArrays</h1>
    <div class="refentry" id="glMultiDrawArrays">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glMultiDrawArrays — render multiple sets of primitives from array data</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glMultiDrawArrays</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLint * <var class="pdparam">first</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLsizei * <var class="pdparam">count</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">drawcount</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>mode</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies what kind of primitives to render.
                    Symbolic constants
                    <code class="constant">GL_POINTS</code>,
                    <code class="constant">GL_LINE_STRIP</code>,
                    <code class="constant">GL_LINE_LOOP</code>,
                    <code class="constant">GL_LINES</code>,
                    <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_LINES_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLE_STRIP</code>,
                    <code class="constant">GL_TRIANGLE_FAN</code>,
                    <code class="constant">GL_TRIANGLES</code>,
                    <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code> and <code class="constant">GL_PATCHES</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>first</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Points to an array of starting indices in the enabled arrays.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>count</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Points to an array of the number of indices to be rendered.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>drawcount</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the size of the first and count
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glMultiDrawArrays</code> specifies multiple sets of geometric primitives
            with very few subroutine calls. Instead of calling a GL procedure
            to pass each individual vertex, normal, texture coordinate, edge
            flag, or color, you can prespecify
            separate arrays of vertices, normals, and colors and use them to
            construct a sequence of primitives with a single
            call to <code class="function">glMultiDrawArrays</code>.
        </p>
        <p>
            <code class="function">glMultiDrawArrays</code> behaves identically to <a class="citerefentry" href="glDrawArrays"><span class="citerefentry"><span class="refentrytitle">glDrawArrays</span></span></a> except that <em class="parameter"><code>drawcount</code></em>
            separate ranges of elements are specified instead.
        </p>
        <p>
            When <code class="function">glMultiDrawArrays</code> is called, it uses <em class="parameter"><code>count</code></em> sequential elements from each
            enabled array to construct a sequence of geometric primitives,
            beginning with element <em class="parameter"><code>first</code></em>. <em class="parameter"><code>mode</code></em> specifies what kind of
            primitives are constructed, and how the array elements
            construct those primitives.
        </p>
        <p>
            Vertex attributes that are modified by <code class="function">glMultiDrawArrays</code> have an
            unspecified value after <code class="function">glMultiDrawArrays</code> returns. Attributes that aren't
            modified remain well defined.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
            <code class="constant">GL_LINES_ADJACENCY</code>,
            <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code> and
            <code class="constant">GL_TRIANGLES_ADJACENCY</code>
            are available only if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>drawcount</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to an
            enabled array and the buffer object's data store is currently mapped.
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glMultiDrawArrays</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006
            Silicon Graphics, Inc.
            Copyright © 2010-2014
            Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glMultiDrawArrays.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glMultiDrawArrays glad_glMultiDrawArrays
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLAPI PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glMultiDrawElements'>OpenGL 4</a><br /><a  href='../gl3/glMultiDrawElements'>OpenGL 3</a><br /><a  href='../gl2/glMultiDrawElements'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glMultiDrawElements</h1>
    <div class="refentry" id="glMultiDrawElements">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glMultiDrawElements — render multiple sets of primitives by specifying indices of array data elements</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glMultiDrawElements</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLsizei * <var class="pdparam">count</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * const * <var class="pdparam">indices</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">drawcount</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>mode</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies what kind of primitives to render.
                    Symbolic constants
                    <code class="constant">GL_POINTS</code>,
                    <code class="constant">GL_LINE_STRIP</code>,
                    <code class="constant">GL_LINE_LOOP</code>,
                    <code class="constant">GL_LINES</code>,
                    <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_LINES_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLE_STRIP</code>,
                    <code class="constant">GL_TRIANGLE_FAN</code>,
                    <code class="constant">GL_TRIANGLES</code>,
                    <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code> and <code class="constant">GL_PATCHES</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>count</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Points to an array of the elements counts.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>type</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the type of the values in <em class="parameter"><code>indices</code></em>. Must be one of
                    <code class="constant">GL_UNSIGNED_BYTE</code>, <code class="constant">GL_UNSIGNED_SHORT</code>, or
                    <code class="constant">GL_UNSIGNED_INT</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>indices</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the location where the indices are stored.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>drawcount</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the size of the <em class="parameter"><code>count</code></em> and <em class="parameter"><code>indices</code></em> arrays.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glMultiDrawElements</code> specifies multiple sets of geometric primitives with very few subroutine
            calls. Instead of calling a GL function to pass each individual vertex,
            normal, texture coordinate, edge flag, or color, you can prespecify
            separate arrays of vertices, normals, and so on, and use them to construct a
            sequence of primitives with a single call to <code class="function">glMultiDrawElements</code>.
        </p>
        <p>
            <code class="function">glMultiDrawElements</code> is identical in operation to <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a> except that
            <em class="parameter"><code>drawcount</code></em> separate lists of elements are specified.
        </p>
        <p>
            Vertex attributes that are modified by <code class="function">glMultiDrawElements</code> have an
            unspecified value after <code class="function">glMultiDrawElements</code> returns. Attributes that aren't
            modified maintain their previous values.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
            <code class="constant">GL_LINES_ADJACENCY</code>,
            <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code> and
            <code class="constant">GL_TRIANGLES_ADJACENCY</code>
            are available only if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>drawcount</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to an
            enabled array or the element array and the buffer object's data store is currently mapped.
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glMultiDrawElements</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glDrawArrays"><span class="citerefentry"><span class="refentrytitle">glDrawArrays</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006
            Silicon Graphics, Inc.
            Copyright © 2010-2014
            Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glMultiDrawElements.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glMultiDrawElements glad_glMultiDrawElements
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
GLAPI PFNGLPOINTPARAMETERFPROC glad_glPointParameterf;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glPointParameter'>OpenGL 4</a><br /><a  href='../gl3/glPointParameter'>OpenGL 3</a><br /><a  href='../gl2/glPointParameter'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glPointParameter</h1>
    <div class="refentry" id="glPointParameter">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glPointParameter — specify point parameters</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameterf</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">param</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameteri</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">param</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameterfv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLfloat * <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameteriv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLint * <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pname</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a single-valued point parameter.
                    <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>, and
                    <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>param</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glPointParameterf</code> and
                    <code class="function">glPointParameteri</code>, specifies the
                    value that <em class="parameter"><code>pname</code></em> will be set to.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>params</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glPointParameterfv</code> and
                    <code class="function">glPointParameteriv</code>, specifies a
                    pointer to an array where the value or values to be
                    assigned to <em class="parameter"><code>pname</code></em> are stored.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            The following values are accepted for <em class="parameter"><code>pname</code></em>:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                    </p>
              <p>
                        <em class="parameter"><code>params</code></em> is a single floating-point value that specifies the threshold value
                        to which point sizes are clamped if they exceed the specified value.  The
                        default value is 1.0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
              </span>
            </dt>
            <dd>
              <p>
                    </p>
              <p>
                        <em class="parameter"><code>params</code></em> is a single enum specifying the point sprite texture coordinate origin, either <code class="constant">GL_LOWER_LEFT</code> or <code class="constant">GL_UPPER_LEFT</code>.
                        The default value is <code class="constant">GL_UPPER_LEFT</code>.
                    </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if the value specified for
            <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code> is less than zero.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated If the value specified for
            <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code> is not <code class="constant">GL_LOWER_LEFT</code> or <code class="constant">GL_UPPER_LEFT</code>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameterf</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameterfv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameteri</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glPointParameteriv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glPointParameter.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glPointParameterf glad_glPointParameterf
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat *params);
GLAPI PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glPointParameter'>OpenGL 4</a><br /><a  href='../gl3/glPointParameter'>OpenGL 3</a><br /><a  href='../gl2/glPointParameter'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glPointParameter</h1>
    <div class="refentry" id="glPointParameter">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glPointParameter — specify point parameters</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameterf</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">param</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameteri</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">param</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameterfv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLfloat * <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameteriv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLint * <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pname</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a single-valued point parameter.
                    <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>, and
                    <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>param</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glPointParameterf</code> and
                    <code class="function">glPointParameteri</code>, specifies the
                    value that <em class="parameter"><code>pname</code></em> will be set to.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>params</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glPointParameterfv</code> and
                    <code class="function">glPointParameteriv</code>, specifies a
                    pointer to an array where the value or values to be
                    assigned to <em class="parameter"><code>pname</code></em> are stored.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            The following values are accepted for <em class="parameter"><code>pname</code></em>:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                    </p>
              <p>
                        <em class="parameter"><code>params</code></em> is a single floating-point value that specifies the threshold value
                        to which point sizes are clamped if they exceed the specified value.  The
                        default value is 1.0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
              </span>
            </dt>
            <dd>
              <p>
                    </p>
              <p>
                        <em class="parameter"><code>params</code></em> is a single enum specifying the point sprite texture coordinate origin, either <code class="constant">GL_LOWER_LEFT</code> or <code class="constant">GL_UPPER_LEFT</code>.
                        The default value is <code class="constant">GL_UPPER_LEFT</code>.
                    </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if the value specified for
            <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code> is less than zero.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated If the value specified for
            <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code> is not <code class="constant">GL_LOWER_LEFT</code> or <code class="constant">GL_UPPER_LEFT</code>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameterf</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameterfv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameteri</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glPointParameteriv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glPointParameter.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glPointParameterfv glad_glPointParameterfv
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
GLAPI PFNGLPOINTPARAMETERIPROC glad_glPointParameteri;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glPointParameter'>OpenGL 4</a><br /><a  href='../gl3/glPointParameter'>OpenGL 3</a><br /><a  href='../gl2/glPointParameter'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glPointParameter</h1>
    <div class="refentry" id="glPointParameter">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glPointParameter — specify point parameters</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameterf</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">param</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameteri</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">param</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameterfv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLfloat * <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameteriv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLint * <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pname</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a single-valued point parameter.
                    <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>, and
                    <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>param</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glPointParameterf</code> and
                    <code class="function">glPointParameteri</code>, specifies the
                    value that <em class="parameter"><code>pname</code></em> will be set to.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>params</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glPointParameterfv</code> and
                    <code class="function">glPointParameteriv</code>, specifies a
                    pointer to an array where the value or values to be
                    assigned to <em class="parameter"><code>pname</code></em> are stored.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            The following values are accepted for <em class="parameter"><code>pname</code></em>:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                    </p>
              <p>
                        <em class="parameter"><code>params</code></em> is a single floating-point value that specifies the threshold value
                        to which point sizes are clamped if they exceed the specified value.  The
                        default value is 1.0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
              </span>
            </dt>
            <dd>
              <p>
                    </p>
              <p>
                        <em class="parameter"><code>params</code></em> is a single enum specifying the point sprite texture coordinate origin, either <code class="constant">GL_LOWER_LEFT</code> or <code class="constant">GL_UPPER_LEFT</code>.
                        The default value is <code class="constant">GL_UPPER_LEFT</code>.
                    </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if the value specified for
            <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code> is less than zero.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated If the value specified for
            <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code> is not <code class="constant">GL_LOWER_LEFT</code> or <code class="constant">GL_UPPER_LEFT</code>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameterf</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameterfv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameteri</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glPointParameteriv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glPointParameter.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glPointParameteri glad_glPointParameteri
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint *params);
GLAPI PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glPointParameter'>OpenGL 4</a><br /><a  href='../gl3/glPointParameter'>OpenGL 3</a><br /><a  href='../gl2/glPointParameter'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glPointParameter</h1>
    <div class="refentry" id="glPointParameter">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glPointParameter — specify point parameters</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameterf</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">param</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameteri</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">param</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameterfv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLfloat * <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPointParameteriv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLint * <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pname</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a single-valued point parameter.
                    <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>, and
                    <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>param</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glPointParameterf</code> and
                    <code class="function">glPointParameteri</code>, specifies the
                    value that <em class="parameter"><code>pname</code></em> will be set to.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>params</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glPointParameterfv</code> and
                    <code class="function">glPointParameteriv</code>, specifies a
                    pointer to an array where the value or values to be
                    assigned to <em class="parameter"><code>pname</code></em> are stored.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            The following values are accepted for <em class="parameter"><code>pname</code></em>:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                    </p>
              <p>
                        <em class="parameter"><code>params</code></em> is a single floating-point value that specifies the threshold value
                        to which point sizes are clamped if they exceed the specified value.  The
                        default value is 1.0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
              </span>
            </dt>
            <dd>
              <p>
                    </p>
              <p>
                        <em class="parameter"><code>params</code></em> is a single enum specifying the point sprite texture coordinate origin, either <code class="constant">GL_LOWER_LEFT</code> or <code class="constant">GL_UPPER_LEFT</code>.
                        The default value is <code class="constant">GL_UPPER_LEFT</code>.
                    </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if the value specified for
            <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code> is less than zero.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated If the value specified for
            <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code> is not <code class="constant">GL_LOWER_LEFT</code> or <code class="constant">GL_UPPER_LEFT</code>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POINT_SPRITE_COORD_ORIGIN</code>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameterf</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameterfv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glPointParameteri</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glPointParameteriv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glPointParameter.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glPointParameteriv glad_glPointParameteriv
typedef void (APIENTRYP PFNGLFOGCOORDFPROC)(GLfloat coord);
GLAPI PFNGLFOGCOORDFPROC glad_glFogCoordf;
#define glFogCoordf glad_glFogCoordf
typedef void (APIENTRYP PFNGLFOGCOORDFVPROC)(const GLfloat *coord);
GLAPI PFNGLFOGCOORDFVPROC glad_glFogCoordfv;
#define glFogCoordfv glad_glFogCoordfv
typedef void (APIENTRYP PFNGLFOGCOORDDPROC)(GLdouble coord);
GLAPI PFNGLFOGCOORDDPROC glad_glFogCoordd;
#define glFogCoordd glad_glFogCoordd
typedef void (APIENTRYP PFNGLFOGCOORDDVPROC)(const GLdouble *coord);
GLAPI PFNGLFOGCOORDDVPROC glad_glFogCoorddv;
#define glFogCoorddv glad_glFogCoorddv
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLFOGCOORDPOINTERPROC glad_glFogCoordPointer;
#define glFogCoordPointer glad_glFogCoordPointer
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
GLAPI PFNGLSECONDARYCOLOR3BPROC glad_glSecondaryColor3b;
#define glSecondaryColor3b glad_glSecondaryColor3b
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *v);
GLAPI PFNGLSECONDARYCOLOR3BVPROC glad_glSecondaryColor3bv;
#define glSecondaryColor3bv glad_glSecondaryColor3bv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
GLAPI PFNGLSECONDARYCOLOR3DPROC glad_glSecondaryColor3d;
#define glSecondaryColor3d glad_glSecondaryColor3d
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *v);
GLAPI PFNGLSECONDARYCOLOR3DVPROC glad_glSecondaryColor3dv;
#define glSecondaryColor3dv glad_glSecondaryColor3dv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
GLAPI PFNGLSECONDARYCOLOR3FPROC glad_glSecondaryColor3f;
#define glSecondaryColor3f glad_glSecondaryColor3f
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *v);
GLAPI PFNGLSECONDARYCOLOR3FVPROC glad_glSecondaryColor3fv;
#define glSecondaryColor3fv glad_glSecondaryColor3fv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IPROC)(GLint red, GLint green, GLint blue);
GLAPI PFNGLSECONDARYCOLOR3IPROC glad_glSecondaryColor3i;
#define glSecondaryColor3i glad_glSecondaryColor3i
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVPROC)(const GLint *v);
GLAPI PFNGLSECONDARYCOLOR3IVPROC glad_glSecondaryColor3iv;
#define glSecondaryColor3iv glad_glSecondaryColor3iv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
GLAPI PFNGLSECONDARYCOLOR3SPROC glad_glSecondaryColor3s;
#define glSecondaryColor3s glad_glSecondaryColor3s
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *v);
GLAPI PFNGLSECONDARYCOLOR3SVPROC glad_glSecondaryColor3sv;
#define glSecondaryColor3sv glad_glSecondaryColor3sv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
GLAPI PFNGLSECONDARYCOLOR3UBPROC glad_glSecondaryColor3ub;
#define glSecondaryColor3ub glad_glSecondaryColor3ub
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *v);
GLAPI PFNGLSECONDARYCOLOR3UBVPROC glad_glSecondaryColor3ubv;
#define glSecondaryColor3ubv glad_glSecondaryColor3ubv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
GLAPI PFNGLSECONDARYCOLOR3UIPROC glad_glSecondaryColor3ui;
#define glSecondaryColor3ui glad_glSecondaryColor3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *v);
GLAPI PFNGLSECONDARYCOLOR3UIVPROC glad_glSecondaryColor3uiv;
#define glSecondaryColor3uiv glad_glSecondaryColor3uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
GLAPI PFNGLSECONDARYCOLOR3USPROC glad_glSecondaryColor3us;
#define glSecondaryColor3us glad_glSecondaryColor3us
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *v);
GLAPI PFNGLSECONDARYCOLOR3USVPROC glad_glSecondaryColor3usv;
#define glSecondaryColor3usv glad_glSecondaryColor3usv
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLSECONDARYCOLORPOINTERPROC glad_glSecondaryColorPointer;
#define glSecondaryColorPointer glad_glSecondaryColorPointer
typedef void (APIENTRYP PFNGLWINDOWPOS2DPROC)(GLdouble x, GLdouble y);
GLAPI PFNGLWINDOWPOS2DPROC glad_glWindowPos2d;
#define glWindowPos2d glad_glWindowPos2d
typedef void (APIENTRYP PFNGLWINDOWPOS2DVPROC)(const GLdouble *v);
GLAPI PFNGLWINDOWPOS2DVPROC glad_glWindowPos2dv;
#define glWindowPos2dv glad_glWindowPos2dv
typedef void (APIENTRYP PFNGLWINDOWPOS2FPROC)(GLfloat x, GLfloat y);
GLAPI PFNGLWINDOWPOS2FPROC glad_glWindowPos2f;
#define glWindowPos2f glad_glWindowPos2f
typedef void (APIENTRYP PFNGLWINDOWPOS2FVPROC)(const GLfloat *v);
GLAPI PFNGLWINDOWPOS2FVPROC glad_glWindowPos2fv;
#define glWindowPos2fv glad_glWindowPos2fv
typedef void (APIENTRYP PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
GLAPI PFNGLWINDOWPOS2IPROC glad_glWindowPos2i;
#define glWindowPos2i glad_glWindowPos2i
typedef void (APIENTRYP PFNGLWINDOWPOS2IVPROC)(const GLint *v);
GLAPI PFNGLWINDOWPOS2IVPROC glad_glWindowPos2iv;
#define glWindowPos2iv glad_glWindowPos2iv
typedef void (APIENTRYP PFNGLWINDOWPOS2SPROC)(GLshort x, GLshort y);
GLAPI PFNGLWINDOWPOS2SPROC glad_glWindowPos2s;
#define glWindowPos2s glad_glWindowPos2s
typedef void (APIENTRYP PFNGLWINDOWPOS2SVPROC)(const GLshort *v);
GLAPI PFNGLWINDOWPOS2SVPROC glad_glWindowPos2sv;
#define glWindowPos2sv glad_glWindowPos2sv
typedef void (APIENTRYP PFNGLWINDOWPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
GLAPI PFNGLWINDOWPOS3DPROC glad_glWindowPos3d;
#define glWindowPos3d glad_glWindowPos3d
typedef void (APIENTRYP PFNGLWINDOWPOS3DVPROC)(const GLdouble *v);
GLAPI PFNGLWINDOWPOS3DVPROC glad_glWindowPos3dv;
#define glWindowPos3dv glad_glWindowPos3dv
typedef void (APIENTRYP PFNGLWINDOWPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
GLAPI PFNGLWINDOWPOS3FPROC glad_glWindowPos3f;
#define glWindowPos3f glad_glWindowPos3f
typedef void (APIENTRYP PFNGLWINDOWPOS3FVPROC)(const GLfloat *v);
GLAPI PFNGLWINDOWPOS3FVPROC glad_glWindowPos3fv;
#define glWindowPos3fv glad_glWindowPos3fv
typedef void (APIENTRYP PFNGLWINDOWPOS3IPROC)(GLint x, GLint y, GLint z);
GLAPI PFNGLWINDOWPOS3IPROC glad_glWindowPos3i;
#define glWindowPos3i glad_glWindowPos3i
typedef void (APIENTRYP PFNGLWINDOWPOS3IVPROC)(const GLint *v);
GLAPI PFNGLWINDOWPOS3IVPROC glad_glWindowPos3iv;
#define glWindowPos3iv glad_glWindowPos3iv
typedef void (APIENTRYP PFNGLWINDOWPOS3SPROC)(GLshort x, GLshort y, GLshort z);
GLAPI PFNGLWINDOWPOS3SPROC glad_glWindowPos3s;
#define glWindowPos3s glad_glWindowPos3s
typedef void (APIENTRYP PFNGLWINDOWPOS3SVPROC)(const GLshort *v);
GLAPI PFNGLWINDOWPOS3SVPROC glad_glWindowPos3sv;
#define glWindowPos3sv glad_glWindowPos3sv
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI PFNGLBLENDCOLORPROC glad_glBlendColor;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glBlendColor'>OpenGL 4</a><br /><a  href='../gl3/glBlendColor'>OpenGL 3</a><br /><a  href='../gl2/glBlendColor'>OpenGL 2</a><br /><a  href='../es3/glBlendColor'>OpenGL ES 3</a><br /><a  href='../es2/glBlendColor'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glBlendColor</h1>
    <div class="refentry" id="glBlendColor">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glBlendColor — set the blend color</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glBlendColor</strong>(</code>
              </td>
              <td>GLfloat <var class="pdparam">red</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">green</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">blue</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">alpha</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term"><em class="parameter"><code>red</code></em>, </span>
              <span class="term"><em class="parameter"><code>green</code></em>, </span>
              <span class="term"><em class="parameter"><code>blue</code></em>, </span>
              <span class="term">
                <em class="parameter">
                  <code>alpha</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    specify the components of <code class="constant">GL_BLEND_COLOR</code>
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            The <code class="constant">GL_BLEND_COLOR</code> may be used to calculate the source and destination
            blending factors. The color components are clamped to the range
            <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mn>0</mn>
                    <mn>1</mn>
                </mfenced>
            </math>
            before being stored. See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> for a complete description of the
            blending operations.
            Initially the <code class="constant">GL_BLEND_COLOR</code> is set to (0, 0, 0, 0).
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The type of the <em class="parameter"><code>red</code></em>,
            <em class="parameter"><code>green</code></em>, <em class="parameter"><code>blue</code></em>,
            and <em class="parameter"><code>alpha</code></em> parameters was changed from
            GLclampf to GLfloat. This change is transparent to user code
            and is described in detail on the
            <a class="citerefentry" href="removedTypes"><span class="citerefentry"><span class="refentrytitle">removedTypes</span></span></a>
            page.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with an argument of <code class="constant">GL_BLEND_COLOR</code>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glBlendColor</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glBlendEquation"><span class="citerefentry"><span class="refentrytitle">glBlendEquation</span></span></a>,
            <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a>,
            <a class="citerefentry" href="glGetString"><span class="citerefentry"><span class="refentrytitle">glGetString</span></span></a>,
            <a class="citerefentry" href="removedTypes"><span class="citerefentry"><span class="refentrytitle">removedTypes</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glBlendColor.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glBlendColor glad_glBlendColor
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
GLAPI PFNGLBLENDEQUATIONPROC glad_glBlendEquation;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glBlendEquation'>OpenGL 4</a><br /><a  href='../gl3/glBlendEquation'>OpenGL 3</a><br /><a  href='../gl2/glBlendEquation'>OpenGL 2</a><br /><a  href='../es3/glBlendEquation'>OpenGL ES 3</a><br /><a  href='../es2/glBlendEquation'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glBlendEquation</h1>
    <div class="refentry" id="glBlendEquation">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glBlendEquation — specify the equation used for both the RGB blend equation and the Alpha blend equation</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glBlendEquation</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glBlendEquationi</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">buf</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">mode</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>buf</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    for <code class="function">glBlendEquationi</code>, specifies the index of the draw buffer
                    for which to set the blend equation.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>mode</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    specifies how source and destination colors are combined.
                    It must be <code class="constant">GL_FUNC_ADD</code>, <code class="constant">GL_FUNC_SUBTRACT</code>,
                    <code class="constant">GL_FUNC_REVERSE_SUBTRACT</code>, <code class="constant">GL_MIN</code>, <code class="constant">GL_MAX</code>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            The blend equations determine how a new pixel (the ''source'' color)
            is combined with a pixel already in the framebuffer (the ''destination''
            color).  This function sets both the RGB blend equation and the alpha
            blend equation to a single equation. <code class="function">glBlendEquationi</code>
            specifies the blend equation for a single draw buffer whereas <code class="function">glBlendEquation</code>
            sets the blend equation for all draw buffers.
        </p>
        <p>
            These equations use the source and destination blend factors
            specified by either <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> or
            <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
            See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> or <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>
            for a description of the various blend factors.
        </p>
        <p>
            In the equations that follow, source and destination
            color components are referred to as
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
                </mfenced>
            </math>
            and
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">d</mi>
                    </msub>
                </mfenced>
            </math>,
            respectively.
            The result color is referred to as
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">R</mi>
                    <mi mathvariant="italic">r</mi>
                    </msub>
                    <msub><mi mathvariant="italic">G</mi>
                    <mi mathvariant="italic">r</mi>
                    </msub>
                    <msub><mi mathvariant="italic">B</mi>
                    <mi mathvariant="italic">r</mi>
                    </msub>
                    <msub><mi mathvariant="italic">A</mi>
                    <mi mathvariant="italic">r</mi>
                    </msub>
                </mfenced>
            </math>.
            The source and destination blend factors are denoted
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">s</mi>
                    <mi mathvariant="italic">R</mi>
                    </msub>
                    <msub><mi mathvariant="italic">s</mi>
                    <mi mathvariant="italic">G</mi>
                    </msub>
                    <msub><mi mathvariant="italic">s</mi>
                    <mi mathvariant="italic">B</mi>
                    </msub>
                    <msub><mi mathvariant="italic">s</mi>
                    <mi mathvariant="italic">A</mi>
                    </msub>
                </mfenced>
            </math>
            and
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <msub><mi mathvariant="italic">d</mi>
                    <mi mathvariant="italic">R</mi>
                    </msub>
                    <msub><mi mathvariant="italic">d</mi>
                    <mi mathvariant="italic">G</mi>
                    </msub>
                    <msub><mi mathvariant="italic">d</mi>
                    <mi mathvariant="italic">B</mi>
                    </msub>
                    <msub><mi mathvariant="italic">d</mi>
                    <mi mathvariant="italic">A</mi>
                    </msub>
                </mfenced>
            </math>,
            respectively.
            For these equations all color components are understood to have values
            in the range
            <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mn>0</mn>
                    <mn>1</mn>
                </mfenced>
            </math>.

        </p>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: left; "/>
              <col style="text-align: left; "/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <span class="bold"><strong> Mode </strong></span>
                        </th>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <span class="bold"><strong> RGB Components </strong></span>
                        </th>
                <th style="text-align: left; border-bottom: 2px solid ; ">
                            <span class="bold"><strong> Alpha Component </strong></span>
                        </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_FUNC_ADD</code>
                        </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mi mathvariant="italic">Rr</mi>
                                <mo>=</mo>
                                <mrow>
                                    <msub><mi mathvariant="italic">R</mi>
                                    <mi mathvariant="italic">s</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">s</mi>
                                    <mi mathvariant="italic">R</mi>
                                    </msub>
                                    <mo>+</mo>
                                    <msub><mi mathvariant="italic">R</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">d</mi>
                                    <mi mathvariant="italic">R</mi>
                                    </msub>
                                </mrow>
                            </mrow>
                        </math>
                        <math overflow="scroll">

                            <mrow>
                                <mi mathvariant="italic">Gr</mi>
                                <mo>=</mo>
                                <mrow>
                                    <msub><mi mathvariant="italic">G</mi>
                                    <mi mathvariant="italic">s</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">s</mi>
                                    <mi mathvariant="italic">G</mi>
                                    </msub>
                                    <mo>+</mo>
                                    <msub><mi mathvariant="italic">G</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">d</mi>
                                    <mi mathvariant="italic">G</mi>
                                    </msub>
                                </mrow>
                            </mrow>
                        </math>
                        <math overflow="scroll">

                            <mrow>
                                <mi mathvariant="italic">Br</mi>
                                <mo>=</mo>
                                <mrow>
                                    <msub><mi mathvariant="italic">B</mi>
                                    <mi mathvariant="italic">s</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">s</mi>
                                    <mi mathvariant="italic">B</mi>
                                    </msub>
                                    <mo>+</mo>
                                    <msub><mi mathvariant="italic">B</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">d</mi>
                                    <mi mathvariant="italic">B</mi>
                                    </msub>
                                </mrow>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mi mathvariant="italic">Ar</mi>
                                <mo>=</mo>
                                <mrow>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">s</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                    <mo>+</mo>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">d</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mrow>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_FUNC_SUBTRACT</code>
                        </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mi mathvariant="italic">Rr</mi>
                                <mo>=</mo>
                                <mrow>
                                    <msub><mi mathvariant="italic">R</mi>
                                    <mi mathvariant="italic">s</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">s</mi>
                                    <mi mathvariant="italic">R</mi>
                                    </msub>
                                    <mo>-</mo>
                                    <msub><mi mathvariant="italic">R</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">d</mi>
                                    <mi mathvariant="italic">R</mi>
                                    </msub>
                                </mrow>
                            </mrow>
                        </math>
                        <math overflow="scroll">

                            <mrow>
                                <mi mathvariant="italic">Gr</mi>
                                <mo>=</mo>
                                <mrow>
                                    <msub><mi mathvariant="italic">G</mi>
                                    <mi mathvariant="italic">s</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">s</mi>
                                    <mi mathvariant="italic">G</mi>
                                    </msub>
                                    <mo>-</mo>
                                    <msub><mi mathvariant="italic">G</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">d</mi>
                                    <mi mathvariant="italic">G</mi>
                                    </msub>
                                </mrow>
                            </mrow>
                        </math>
                        <math overflow="scroll">

                            <mrow>
                                <mi mathvariant="italic">Br</mi>
                                <mo>=</mo>
                                <mrow>
                                    <msub><mi mathvariant="italic">B</mi>
                                    <mi mathvariant="italic">s</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">s</mi>
                                    <mi mathvariant="italic">B</mi>
                                    </msub>
                                    <mo>-</mo>
                                    <msub><mi mathvariant="italic">B</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">d</mi>
                                    <mi mathvariant="italic">B</mi>
                                    </msub>
                                </mrow>
                            </mrow>
                        </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                        <math overflow="scroll">

                            <mrow>
                                <mi mathvariant="italic">Ar</mi>
                                <mo>=</mo>
                                <mrow>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">s</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">s</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                    <mo>-</mo>
                                    <msub><mi mathvariant="italic">A</mi>
                                    <mi mathvariant="italic">d</mi>
                                    </msub>
                                    <mo>⁢</mo>
                                    <msub><mi mathvariant="italic">d</mi>
                                    <mi mathvariant="italic">A</mi>
                                    </msub>
                                </mrow>
                            </mrow>
                        </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_FUNC_REVERSE_SUBTRACT</code>
                        </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Rr</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <msub><mi mathvariant="italic">R</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <mo>⁢</mo>
                                        <msub><mi mathvariant="italic">d</mi>
                                        <mi mathvariant="italic">R</mi>
                                        </msub>
                                        <mo>-</mo>
                                        <msub><mi mathvariant="italic">R</mi>
                                        <mi mathvariant="italic">s</mi>
                                        </msub>
                                        <mo>⁢</mo>
                                        <msub><mi mathvariant="italic">s</mi>
                                        <mi mathvariant="italic">R</mi>
                                        </msub>
                                    </mrow>
                                </mrow>
                            </math>
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Gr</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <msub><mi mathvariant="italic">G</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <mo>⁢</mo>
                                        <msub><mi mathvariant="italic">d</mi>
                                        <mi mathvariant="italic">G</mi>
                                        </msub>
                                        <mo>-</mo>
                                        <msub><mi mathvariant="italic">G</mi>
                                        <mi mathvariant="italic">s</mi>
                                        </msub>
                                        <mo>⁢</mo>
                                        <msub><mi mathvariant="italic">s</mi>
                                        <mi mathvariant="italic">G</mi>
                                        </msub>
                                    </mrow>
                                </mrow>
                            </math>
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Br</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <msub><mi mathvariant="italic">B</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <mo>⁢</mo>
                                        <msub><mi mathvariant="italic">d</mi>
                                        <mi mathvariant="italic">B</mi>
                                        </msub>
                                        <mo>-</mo>
                                        <msub><mi mathvariant="italic">B</mi>
                                        <mi mathvariant="italic">s</mi>
                                        </msub>
                                        <mo>⁢</mo>
                                        <msub><mi mathvariant="italic">s</mi>
                                        <mi mathvariant="italic">B</mi>
                                        </msub>
                                    </mrow>
                                </mrow>
                            </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Ar</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">d</mi>
                                        </msub>
                                        <mo>⁢</mo>
                                        <msub><mi mathvariant="italic">d</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                        <mo>-</mo>
                                        <msub><mi mathvariant="italic">A</mi>
                                        <mi mathvariant="italic">s</mi>
                                        </msub>
                                        <mo>⁢</mo>
                                        <msub><mi mathvariant="italic">s</mi>
                                        <mi mathvariant="italic">A</mi>
                                        </msub>
                                    </mrow>
                                </mrow>
                            </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_MIN</code>
                        </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Rr</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <mi mathvariant="italic">min</mi>
                                        <mo>⁡</mo>
                                        <mfenced open="(" close=")">
                                            <mrow>
                                                <msub><mi mathvariant="italic">R</mi>
                                                <mi mathvariant="italic">s</mi>
                                                </msub>
                                            </mrow>
                                            <mrow>
                                                <msub><mi mathvariant="italic">R</mi>
                                                <mi mathvariant="italic">d</mi>
                                                </msub>
                                            </mrow>
                                        </mfenced>
                                    </mrow>
                                </mrow>
                            </math>
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Gr</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <mi mathvariant="italic">min</mi>
                                        <mo>⁡</mo>
                                        <mfenced open="(" close=")">
                                            <mrow>
                                                <msub><mi mathvariant="italic">G</mi>
                                                <mi mathvariant="italic">s</mi>
                                                </msub>
                                            </mrow>
                                            <mrow>
                                                <msub><mi mathvariant="italic">G</mi>
                                                <mi mathvariant="italic">d</mi>
                                                </msub>
                                            </mrow>
                                        </mfenced>
                                    </mrow>
                                </mrow>
                            </math>
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Br</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <mi mathvariant="italic">min</mi>
                                        <mo>⁡</mo>
                                        <mfenced open="(" close=")">
                                            <mrow>
                                                <msub><mi mathvariant="italic">B</mi>
                                                <mi mathvariant="italic">s</mi>
                                                </msub>
                                            </mrow>
                                            <mrow>
                                                <msub><mi mathvariant="italic">B</mi>
                                                <mi mathvariant="italic">d</mi>
                                                </msub>
                                            </mrow>
                                        </mfenced>
                                    </mrow>
                                </mrow>
                            </math>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Ar</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <mi mathvariant="italic">min</mi>
                                        <mo>⁡</mo>
                                        <mfenced open="(" close=")">
                                            <mrow>
                                                <msub><mi mathvariant="italic">A</mi>
                                                <mi mathvariant="italic">s</mi>
                                                </msub>
                                            </mrow>
                                            <mrow>
                                                <msub><mi mathvariant="italic">A</mi>
                                                <mi mathvariant="italic">d</mi>
                                                </msub>
                                            </mrow>
                                        </mfenced>
                                    </mrow>
                                </mrow>
                            </math>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                        <code class="constant">GL_MAX</code>
                        </td>
                <td style="text-align: left; border-right: 2px solid ; ">
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Rr</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <mi mathvariant="italic">max</mi>
                                        <mo>⁡</mo>
                                        <mfenced open="(" close=")">
                                            <mrow>
                                                <msub><mi mathvariant="italic">R</mi>
                                                <mi mathvariant="italic">s</mi>
                                                </msub>
                                            </mrow>
                                            <mrow>
                                                <msub><mi mathvariant="italic">R</mi>
                                                <mi mathvariant="italic">d</mi>
                                                </msub>
                                            </mrow>
                                        </mfenced>
                                    </mrow>
                                </mrow>
                            </math>
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Gr</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <mi mathvariant="italic">max</mi>
                                        <mo>⁡</mo>
                                        <mfenced open="(" close=")">
                                            <mrow>
                                                <msub><mi mathvariant="italic">G</mi>
                                                <mi mathvariant="italic">s</mi>
                                                </msub>
                                            </mrow>
                                            <mrow>
                                                <msub><mi mathvariant="italic">G</mi>
                                                <mi mathvariant="italic">d</mi>
                                                </msub>
                                            </mrow>
                                        </mfenced>
                                    </mrow>
                                </mrow>
                            </math>
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Br</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <mi mathvariant="italic">max</mi>
                                        <mo>⁡</mo>
                                        <mfenced open="(" close=")">
                                            <mrow>
                                                <msub><mi mathvariant="italic">B</mi>
                                                <mi mathvariant="italic">s</mi>
                                                </msub>
                                            </mrow>
                                            <mrow>
                                                <msub><mi mathvariant="italic">B</mi>
                                                <mi mathvariant="italic">d</mi>
                                                </msub>
                                            </mrow>
                                        </mfenced>
                                    </mrow>
                                </mrow>
                            </math>
                        </td>
                <td style="text-align: left; ">
                            <math overflow="scroll">

                                <mrow>
                                    <mi mathvariant="italic">Ar</mi>
                                    <mo>=</mo>
                                    <mrow>
                                        <mi mathvariant="italic">max</mi>
                                        <mo>⁡</mo>
                                        <mfenced open="(" close=")">
                                            <mrow>
                                                <msub><mi mathvariant="italic">A</mi>
                                                <mi mathvariant="italic">s</mi>
                                                </msub>
                                            </mrow>
                                            <mrow>
                                                <msub><mi mathvariant="italic">A</mi>
                                                <mi mathvariant="italic">d</mi>
                                                </msub>
                                            </mrow>
                                        </mfenced>
                                    </mrow>
                                </mrow>
                            </math>
                        </td>
              </tr>
            </tbody>
          </table>
        </div>
        <p>
        </p>
        <p>
            The results of these equations are clamped to the range
                        <math overflow="scroll">

                            <mfenced open="[" close="]">
                                <mn>0</mn>
                                <mn>1</mn>
                            </mfenced>
                        </math>.
        </p>
        <p>
            The <code class="constant">GL_MIN</code> and <code class="constant">GL_MAX</code> equations are useful for applications
            that analyze image data (image thresholding against a constant color,
            for example).
            The <code class="constant">GL_FUNC_ADD</code> equation is useful
            for antialiasing and transparency, among other things.
        </p>
        <p>
            Initially, both the RGB blend equation and the alpha blend equation are set to <code class="constant">GL_FUNC_ADD</code>.
        </p>
        <p>
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The <code class="constant">GL_MIN</code>, and <code class="constant">GL_MAX</code> equations do not use
            the source or destination factors, only the source and destination colors.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not one of
            <code class="constant">GL_FUNC_ADD</code>, <code class="constant">GL_FUNC_SUBTRACT</code>, <code class="constant">GL_FUNC_REVERSE_SUBTRACT</code>,
            <code class="constant">GL_MAX</code>, or <code class="constant">GL_MIN</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated by <code class="function">glBlendEquationi</code> if <em class="parameter"><code>buf</code></em> is greater
            than or equal to the value of <code class="constant">GL_MAX_DRAW_BUFFERS</code>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with an argument of <code class="constant">GL_BLEND_EQUATION_RGB</code>
         </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with an argument of <code class="constant">GL_BLEND_EQUATION_ALPHA</code>
         </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glBlendEquation</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glBlendEquationi</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glBlendColor"><span class="citerefentry"><span class="refentrytitle">glBlendColor</span></span></a>,
            <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a>
            <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glBlendEquation.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glBlendEquation glad_glBlendEquation
#endif
#endif