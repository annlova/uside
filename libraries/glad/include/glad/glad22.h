#ifndef __uside_glad22_h_
#define __uside_glad22_h_
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
GLAPI int GLAD_GL_VERSION_1_2;
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDrawRangeElements'>OpenGL 4</a><br /><a  href='../gl3/glDrawRangeElements'>OpenGL 3</a><br /><a  href='../gl2/glDrawRangeElements'>OpenGL 2</a><br /><a  href='../es3/glDrawRangeElements'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glDrawRangeElements</h1>
    <div class="refentry" id="glDrawRangeElements">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDrawRangeElements — render primitives from array data</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDrawRangeElements</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">start</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">end</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">count</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">indices</var><code>)</code>;</td>
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
                  <code>start</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the minimum array index contained in <em class="parameter"><code>indices</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>end</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the maximum array index contained in <em class="parameter"><code>indices</code></em>.
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
                    Specifies the number of elements to be rendered.
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
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDrawRangeElements</code> is a restricted form of <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a>. <em class="parameter"><code>mode</code></em>, <em class="parameter"><code>start</code></em>, <em class="parameter"><code>end</code></em>,
            and <em class="parameter"><code>count</code></em> match the corresponding arguments to <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a>, with
            the additional constraint that all values in the arrays <em class="parameter"><code>count</code></em> must lie
            between <em class="parameter"><code>start</code></em> and <em class="parameter"><code>end</code></em>, inclusive.
        </p>
        <p>
            Implementations denote recommended maximum amounts of vertex and
            index data,
            which may be queried by calling <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument
            <code class="constant">GL_MAX_ELEMENTS_VERTICES</code> and <code class="constant">GL_MAX_ELEMENTS_INDICES</code>.
            If
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">end</mi>
                    <mo>-</mo>
                    <mi mathvariant="italic">start</mi>
                    <mo>+</mo>
                    <mn>1</mn>
                </mrow>
            </math>
            is greater than the value of
            <code class="constant">GL_MAX_ELEMENTS_VERTICES</code>, or if <em class="parameter"><code>count</code></em> is greater than the value of
            <code class="constant">GL_MAX_ELEMENTS_INDICES</code>, then the call may operate at reduced
            performance.  There is no requirement that all vertices in the range
            <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mi mathvariant="italic">start</mi>
                    <mi mathvariant="italic">end</mi>
                </mfenced>
            </math>
            be referenced.  However, the implementation may
            partially process unused vertices, reducing performance from what could
            be achieved with an optimal index set.
        </p>
        <p>
            When <code class="function">glDrawRangeElements</code> is called, it uses <em class="parameter"><code>count</code></em> sequential elements from an
            enabled array, starting at <em class="parameter"><code>start</code></em> to construct a sequence of
            geometric primitives. <em class="parameter"><code>mode</code></em> specifies what kind of primitives are
            constructed, and how the array elements construct these primitives. If
            more than one array is enabled, each is used.
        </p>
        <p>
            Vertex attributes that are modified by <code class="function">glDrawRangeElements</code> have an
            unspecified value after <code class="function">glDrawRangeElements</code> returns. Attributes that aren't
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
            It is an error for indices to lie outside the range
            <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mi mathvariant="italic">start</mi>
                    <mi mathvariant="italic">end</mi>
                </mfenced>
            </math>,
            but implementations may not check for this situation. Such indices
            cause implementation-dependent behavior.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>count</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">end</mi>
                    <mo>&lt;</mo>
                    <mi mathvariant="italic">start</mi>
                </mrow>
            </math>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a geometry shader is active and <em class="parameter"><code>mode</code></em>
            is incompatible with the input primitive type of the geometry shader in the currently installed program object.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to an
            enabled array or the element array and the buffer object's data store is currently mapped.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_MAX_ELEMENTS_VERTICES</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_MAX_ELEMENTS_INDICES</code>
        </p>
      </div>
      <div class='refsect1' id='tutorials'><h2>Tutorials</h2><p></p></div>
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
                  <code class="function">glDrawRangeElements</code>
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
            <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a>,
            <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDrawRangeElements.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glDrawRangeElements glad_glDrawRangeElements
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXIMAGE3DPROC glad_glTexImage3D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glTexImage3D'>OpenGL 4</a><br /><a  href='../gl3/glTexImage3D'>OpenGL 3</a><br /><a  href='../gl2/glTexImage3D'>OpenGL 2</a><br /><a  href='../es3/glTexImage3D'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glTexImage3D</h1>
    <div class="refentry" id="glTexImage3D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glTexImage3D — specify a three-dimensional texture image</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTexImage3D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">internalFormat</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">depth</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">border</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">data</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target texture.
                    Must be one of <code class="constant">GL_TEXTURE_3D</code>, <code class="constant">GL_PROXY_TEXTURE_3D</code>,
                    <code class="constant">GL_TEXTURE_2D_ARRAY</code> or <code class="constant">GL_PROXY_TEXTURE_2D_ARRAY</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level
                    <math overflow="scroll"><mi mathvariant="italic">n</mi></math>
                    is the
                    <math overflow="scroll">

                        <msup><mi mathvariant="italic">n</mi>
                        <mi mathvariant="italic">th</mi>
                        </msup>
                    </math>
                    mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>internalFormat</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of color components in the texture.
                    Must be one of base internal formats given in Table 1,
                    one of the sized internal formats given in Table 2, or one
                    of the compressed internal formats given in Table 3, below.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture image.
                    All implementations support 3D texture images that are at least 16 texels
                    wide.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the height of the texture image.
                    All implementations support 3D texture images that are at least 256 texels
                    high.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>depth</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the depth of the texture image, or the number of layers in a texture array.
                    All implementations support 3D texture images that are at least 256 texels
                    deep, and texture arrays that are at least 256 layers deep.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>border</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    This value must be 0.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>format</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the format of the pixel data.
                    The following symbolic values are accepted:
                    <code class="constant">GL_RED</code>,
                    <code class="constant">GL_RG</code>,
                    <code class="constant">GL_RGB</code>,
                    <code class="constant">GL_BGR</code>,
                    <code class="constant">GL_RGBA</code>,
                    <code class="constant">GL_BGRA</code>,
                    <code class="constant">GL_RED_INTEGER</code>,
                    <code class="constant">GL_RG_INTEGER</code>,
                    <code class="constant">GL_RGB_INTEGER</code>,
                    <code class="constant">GL_BGR_INTEGER</code>,
                    <code class="constant">GL_RGBA_INTEGER</code>,
                    <code class="constant">GL_BGRA_INTEGER</code>,
                    <code class="constant">GL_STENCIL_INDEX</code>,
                    <code class="constant">GL_DEPTH_COMPONENT</code>,
                    <code class="constant">GL_DEPTH_STENCIL</code>.
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
                    Specifies the data type of the pixel data.
                    The following symbolic values are accepted:
                    <code class="constant">GL_UNSIGNED_BYTE</code>,
                    <code class="constant">GL_BYTE</code>,
                    <code class="constant">GL_UNSIGNED_SHORT</code>,
                    <code class="constant">GL_SHORT</code>,
                    <code class="constant">GL_UNSIGNED_INT</code>,
                    <code class="constant">GL_INT</code>,
                    <code class="constant">GL_FLOAT</code>,
                    <code class="constant">GL_UNSIGNED_BYTE_3_3_2</code>,
                    <code class="constant">GL_UNSIGNED_BYTE_2_3_3_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_6_5</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_6_5_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_5_5_1</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_1_5_5_5_REV</code>,
                    <code class="constant">GL_UNSIGNED_INT_8_8_8_8</code>,
                    <code class="constant">GL_UNSIGNED_INT_8_8_8_8_REV</code>,
                    <code class="constant">GL_UNSIGNED_INT_10_10_10_2</code>, and
                    <code class="constant">GL_UNSIGNED_INT_2_10_10_10_REV</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>data</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the image data in memory.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Texturing maps a portion of a specified texture image
            onto each graphical primitive for which texturing is enabled.
            To enable and disable three-dimensional texturing, call <a class="citerefentry" href="glEnable"><span class="citerefentry"><span class="refentrytitle">glEnable</span></span></a>
            and <a class="citerefentry" href="glDisable"><span class="citerefentry"><span class="refentrytitle">glDisable</span></span></a> with argument <code class="constant">GL_TEXTURE_3D</code>.
        </p>
        <p>
            To define texture images, call <code class="function">glTexImage3D</code>.
            The arguments describe the parameters of the texture image,
            such as height,
            width, depth,
            width of the border,
            level-of-detail number
            (see <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>),
            and number of color components provided.
            The last three arguments describe how the image is represented in memory.
        </p>
        <p>
            If <em class="parameter"><code>target</code></em> is <code class="constant">GL_PROXY_TEXTURE_3D</code>, no data is read from <em class="parameter"><code>data</code></em>, but
            all of the texture image state is recalculated, checked for
            consistency, and checked
            against the implementation's capabilities. If the implementation cannot
            handle a texture of the requested texture size, it sets
            all of the image state to 0,
            but does not generate an error (see <a class="citerefentry" href="glGetError"><span class="citerefentry"><span class="refentrytitle">glGetError</span></span></a>). To query for an
            entire mipmap array, use an image array level greater than or equal to
            1.
        </p>
        <p>
            If <em class="parameter"><code>target</code></em> is <code class="constant">GL_TEXTURE_3D</code>,
            data is read from <em class="parameter"><code>data</code></em> as a sequence of signed or unsigned bytes,
            shorts,
            or longs,
            or single-precision floating-point values,
            depending on <em class="parameter"><code>type</code></em>.
            These values are grouped into sets of one,
            two,
            three,
            or four values,
            depending on <em class="parameter"><code>format</code></em>,
            to form elements.
            Each data byte is treated as eight 1-bit elements,
            with bit ordering determined by <code class="constant">GL_UNPACK_LSB_FIRST</code>
            (see <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>).
        </p>
        <p>
            If a non-zero named buffer object is bound to the <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target
            (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is
            specified, <em class="parameter"><code>data</code></em> is treated as a byte offset into the buffer object's data store.
        </p>
        <p>
            The first element corresponds to the lower left corner of the texture
            image.
            Subsequent elements progress left-to-right through the remaining texels
            in the lowest row of the texture image, and then in successively higher
            rows of the texture image.
            The final element corresponds to the upper right corner of the texture
            image.
        </p>
        <p>
            <em class="parameter"><code>format</code></em> determines the composition of each element in <em class="parameter"><code>data</code></em>.
            It can assume one of these symbolic values:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_RED</code>
              </span>
            </dt>
            <dd>
              <p>
                        Each element is a single red component.
                        The GL converts it to floating point and assembles it into an RGBA element
                        by attaching 0 for green and blue, and 1 for alpha.
                        Each component is clamped to the range [0,1].
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_RG</code>
              </span>
            </dt>
            <dd>
              <p>
                        Each element is a red and green pair.
                        The GL converts each to floating point and assembles it into an RGBA element
                        by attaching 0 for blue, and 1 for alpha.
                        Each component is clamped to the range [0,1].
                    </p>
            </dd>
            <dt>
              <span class="term"><code class="constant">GL_RGB</code>, </span>
              <span class="term">
                <code class="constant">GL_BGR</code>
              </span>
            </dt>
            <dd>
              <p>
                        Each element is an RGB triple.
                        The GL converts it to floating point and assembles it into an RGBA element
                        by attaching 1 for alpha.
                        Each component is clamped to the range [0,1].
                    </p>
            </dd>
            <dt>
              <span class="term"><code class="constant">GL_RGBA</code>, </span>
              <span class="term">
                <code class="constant">GL_BGRA</code>
              </span>
            </dt>
            <dd>
              <p>
                        Each element contains all four components.
                        Each component is clamped to the range [0,1].
                    </p>
            </dd>
          </dl>
        </div>
        <p>
            If an application wants to store the texture at a certain
            resolution or in a certain format, it can request the resolution
            and format with <em class="parameter"><code>internalFormat</code></em>. The GL will choose an internal
            representation that closely approximates that requested by <em class="parameter"><code>internalFormat</code></em>, but
            it may not match exactly.
            (The representations specified by <code class="constant">GL_RED</code>, <code class="constant">GL_RG</code>, <code class="constant">GL_RGB</code>,
            and <code class="constant">GL_RGBA</code> must match exactly.)
        </p>
        <p>
            <em class="parameter"><code>internalFormat</code></em> may be one of the base internal formats shown in
            Table 1, below
        </p>
        <p>
            </p>
        <div class="table" id="idm2352">
          <div class="table-title">Table 1. Base Internal Formats</div>
          <div class="table-contents">
            <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
              <colgroup>
                <col style="text-align: left; "/>
                <col style="text-align: left; "/>
                <col style="text-align: left; "/>
              </colgroup>
              <thead>
                <tr>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Base Internal Format</strong></span>
                </th>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>RGBA, Depth and Stencil Values</strong></span>
                </th>
                  <th style="text-align: left; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Internal Components</strong></span>
                </th>
                </tr>
              </thead>
              <tbody>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_DEPTH_COMPONENT</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">Depth</td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">D</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_DEPTH_STENCIL</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">Depth, Stencil</td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">D, S</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">Red</td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">R</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">Red, Green</td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">R, G</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">Red, Green, Blue</td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">R, G, B</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; ">Red, Green, Blue, Alpha</td>
                  <td style="text-align: left; ">R, G, B, A</td>
                </tr>
              </tbody>
            </table>
          </div>
        </div>
        <p><br class="table-break"/>
        </p>
        <p>
            <em class="parameter"><code>internalFormat</code></em> may also be one of the sized internal formats
            shown in Table 2, below
        </p>
        <p>
            </p>
        <div class="table" id="idp782672">
          <div class="table-title">Table 2. Sized Internal Formats</div>
          <div class="table-contents">
            <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
              <colgroup>
                <col style="text-align: left; "/>
                <col style="text-align: left; "/>
                <col style="text-align: center; "/>
                <col style="text-align: center; "/>
                <col style="text-align: center; "/>
                <col style="text-align: center; "/>
                <col style="text-align: center; "/>
              </colgroup>
              <thead>
                <tr>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Sized Internal Format</strong></span>
                </th>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Base Internal Format</strong></span>
                </th>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Red Bits</strong></span>
                </th>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Green Bits</strong></span>
                </th>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Blue Bits</strong></span>
                </th>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Alpha Bits</strong></span>
                </th>
                  <th style="text-align: left; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Shared Bits</strong></span>
                </th>
                </tr>
              </thead>
              <tbody>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R8</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R8_SNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R16</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R16_SNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG8</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG8_SNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG16</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG16_SNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R3_G3_B2</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">3</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">3</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB4</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB5</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">5</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">5</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">5</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB8</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB8_SNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB10</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB12</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">12</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">12</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">12</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB16_SNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA2</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA4</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB5_A1</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">5</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">5</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">5</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA8</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA8_SNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">s8</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB10_A2</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB10_A2UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui2</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA12</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">12</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">12</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">12</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">12</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA16</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">16</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_SRGB8</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_SRGB8_ALPHA8</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">8</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R16F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG16F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB16F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA16F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f16</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R32F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG32F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB32F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA32F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f32</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R11F_G11F_B10F</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f11</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f11</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">f10</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB9_E5</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">9</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">9</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">9</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; ">5</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R8I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R8UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R16I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R16UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R32I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_R32UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG8I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG8UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG16I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG16UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG32I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG32UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB8I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB8UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB16I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB16UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB32I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB32UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; "> </td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA8I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i8</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA8UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui8</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA16I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i16</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA16UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">ui16</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA32I</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">i32</td>
                  <td style="text-align: center; border-bottom: 2px solid ; "> </td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; ">
                    <code class="constant">GL_RGBA32UI</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: center; border-right: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; ">ui32</td>
                  <td style="text-align: center; border-right: 2px solid ; ">ui32</td>
                  <td style="text-align: center; "> </td>
                </tr>
              </tbody>
            </table>
          </div>
        </div>
        <p><br class="table-break"/>
        </p>
        <p>
            Finally, <em class="parameter"><code>internalFormat</code></em> may also be one of the generic or compressed
            compressed texture formats shown in Table 3 below
        </p>
        <p>
            </p>
        <div class="table" id="idp783488">
          <div class="table-title">Table 3. Compressed Internal Formats</div>
          <div class="table-contents">
            <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
              <colgroup>
                <col style="text-align: left; "/>
                <col style="text-align: left; "/>
                <col style="text-align: left; "/>
              </colgroup>
              <thead>
                <tr>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Compressed Internal Format</strong></span>
                </th>
                  <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Base Internal Format</strong></span>
                </th>
                  <th style="text-align: left; border-bottom: 2px solid ; ">
                    <span class="bold"><strong>Type</strong></span>
                </th>
                </tr>
              </thead>
              <tbody>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RED</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Generic</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RG</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Generic</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RGB</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Generic</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RGBA</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Generic</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_SRGB</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Generic</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_SRGB_ALPHA</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Generic</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RED_RGTC1</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Specific</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_SIGNED_RED_RGTC1</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RED</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Specific</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RG_RGTC2</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Specific</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_SIGNED_RG_RGTC2</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RG</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Specific</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RGBA_BPTC_UNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Specific</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGBA</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Specific</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: left; border-bottom: 2px solid ; ">Specific</td>
                </tr>
                <tr>
                  <td style="text-align: left; border-right: 2px solid ; ">
                    <code class="constant">GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT</code>
                  </td>
                  <td style="text-align: left; border-right: 2px solid ; ">
                    <code class="constant">GL_RGB</code>
                  </td>
                  <td style="text-align: left; ">Specific</td>
                </tr>
              </tbody>
            </table>
          </div>
        </div>
        <p><br class="table-break"/>
        </p>
        <p>
                If the <em class="parameter"><code>internalFormat</code></em> parameter is one of the generic compressed formats,
                <code class="constant">GL_COMPRESSED_RED</code>, <code class="constant">GL_COMPRESSED_RG</code>,
                <code class="constant">GL_COMPRESSED_RGB</code>, or
                <code class="constant">GL_COMPRESSED_RGBA</code>, the GL will replace the internal format with the symbolic constant for a specific internal format and compress the texture before storage.  If no corresponding internal format is available, or the GL can not compress that image for any reason, the internal format is instead replaced with a corresponding base internal format.
        </p>
        <p>
            If the <em class="parameter"><code>internalFormat</code></em> parameter is
            <code class="constant">GL_SRGB</code>,
                              <code class="constant">GL_SRGB8</code>,
                              <code class="constant">GL_SRGB_ALPHA</code>, or
                              <code class="constant">GL_SRGB8_ALPHA8</code>, the texture is treated as if the red, green, blue, or luminance components are encoded in the sRGB color space.    Any alpha component is left unchanged.  The conversion from the sRGB encoded component
                        <math overflow="scroll">
                    <msub><mi mathvariant="italic">c</mi>
                    <mi mathvariant="italic">s</mi>
                    </msub>
            </math>
                        to a linear component
                        <math overflow="scroll">
                    <msub><mi mathvariant="italic">c</mi>
                    <mi mathvariant="italic">l</mi>
                    </msub>
            </math>
            is:
                </p>
        <p>
                        <math overflow="scroll">
                        <mrow>
                                <msub>
                                  <mi mathvariant="italic">c</mi>
                                  <mi mathvariant="italic">l</mi>
                                </msub>
                                <mo>=</mo>
                                <mrow>
                                  <mo>{</mo>

                                  <mtable columnalign="left">
                                        <mtr>
                                          <mtd columnalign="left">
                                                <mfrac>
                                                  <msub>
                                                        <mi mathvariant="italic">c</mi>
                                                        <mi mathvariant="italic">s</mi>
                                                  </msub>
                                                  <mn>12.92</mn>
                                                </mfrac>
                                          </mtd>
                                          <mtd columnalign="left">
                                                <mrow>
                                                  <mspace width="1ex"/>
                                                  <mo>if</mo>
                                                  <mspace width="1ex"/>
                                                </mrow>
                                                <msub>
                                                  <mi mathvariant="italic">c</mi>
                                                  <mi mathvariant="italic">s</mi>
                                                </msub>
                                                <mo>≤</mo>
                                                <mn>0.04045</mn>
                                          </mtd>
                                        </mtr>
                                        <mtr>
                                        <mtd columnalign="left">
                                        <msup>
                                          <mrow>
                                                <mo>(</mo>
                                                <mfrac>
                                                  <mrow>
                                                        <msub>
                                                          <mi>c</mi>
                                                          <mi>s</mi>
                                                        </msub>
                                                        <mo>+</mo>
                                                        <mn>0.055</mn>
                                                  </mrow>
                                                  <mn>1.055</mn>
                                                </mfrac>
                                                <mo>)</mo>
                                          </mrow>
                                          <mn>2.4</mn>
                                        </msup>
                                        </mtd>
                                  <mtd columnalign="left">
                                                <mrow>
                                                  <mspace width="1ex"/>
                                                  <mo>if</mo>
                                                  <mspace width="1ex"/>
                                                </mrow>
                                                <msub>
                                                  <mi mathvariant="italic">c</mi>
                                                  <mi mathvariant="italic">s</mi>
                                                </msub>
                                                <mo>&gt;</mo>
                                                <mn>0.04045</mn>
                                          </mtd>
                                        </mtr>
                                  </mtable>
                                </mrow>
                                </mrow>
                        </math>
                </p>
        <p>
                        Assume
                        <math overflow="scroll">
                                                                <msub><mi mathvariant="italic">c</mi>
                                                                <mi mathvariant="italic">s</mi>
                                                                </msub>
                                                </math>
                        is the sRGB component in the range [0,1].
       </p>
        <p>
            Use the <code class="constant">GL_PROXY_TEXTURE_3D</code> target to try out a resolution and
            format. The implementation will
            update and recompute its best match for the requested storage resolution
            and format. To then query this state, call <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>.
            If the texture cannot be accommodated, texture state is set to 0.
        </p>
        <p>
            A one-component texture image uses only the red component of the RGBA
            color extracted from <em class="parameter"><code>data</code></em>.
            A two-component image uses the R and A values.
            A three-component image uses the R, G, and B values.
            A four-component image uses all of the RGBA components.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a> mode affects texture images.
        </p>
        <p>
            <em class="parameter"><code>data</code></em> may be a null pointer.
            In this case texture memory is
            allocated to accommodate a texture of width <em class="parameter"><code>width</code></em>, height <em class="parameter"><code>height</code></em>,
            and depth <em class="parameter"><code>depth</code></em>.
            You can then download subtextures to initialize this
            texture memory.
            The image is undefined if the user tries to apply
            an uninitialized portion of the texture image to a primitive.
        </p>
        <p>
            <code class="function">glTexImage3D</code> specifies the three-dimensional texture for the current texture unit,
            specified with <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
        </p>
        <p>
            <code class="constant">GL_STENCIL_INDEX</code> may be used for <em class="parameter"><code>format</code></em> only if the GL
            version is 4.4 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>target</code></em> is not <code class="constant">GL_TEXTURE_3D</code>
            or <code class="constant">GL_PROXY_TEXTURE_3D</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>format</code></em> is not an accepted
            format constant.  Format constants other than <code class="constant">GL_STENCIL_INDEX</code> and <code class="constant">GL_DEPTH_COMPONENT</code>
            are accepted.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>type</code></em> is not a type constant.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>level</code></em> is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> may be generated if <em class="parameter"><code>level</code></em> is greater than
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">log</mi>
                    <mn>2</mn>
                    </msub>
                    <mo>⁡</mo>
                    <mfenced open="(" close=")">
                        <mi mathvariant="italic">max</mi>
                    </mfenced>
                </mrow>
            </math>,
            where <span class="emphasis"><em>max</em></span> is the returned value of <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>internalFormat</code></em> is not one of the
            accepted resolution and format symbolic constants.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>width</code></em>, <em class="parameter"><code>height</code></em>, or <em class="parameter"><code>depth</code></em> is less than 0 or greater than <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>border</code></em> is not 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>type</code></em> is one of
            <code class="constant">GL_UNSIGNED_BYTE_3_3_2</code>,
            <code class="constant">GL_UNSIGNED_BYTE_2_3_3_REV</code>,
            <code class="constant">GL_UNSIGNED_SHORT_5_6_5</code>, or
            <code class="constant">GL_UNSIGNED_SHORT_5_6_5_REV</code>
            and <em class="parameter"><code>format</code></em> is not <code class="constant">GL_RGB</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>type</code></em> is one of
            <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4</code>,
            <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4_REV</code>,
            <code class="constant">GL_UNSIGNED_SHORT_5_5_5_1</code>,
            <code class="constant">GL_UNSIGNED_SHORT_1_5_5_5_REV</code>,
            <code class="constant">GL_UNSIGNED_INT_8_8_8_8</code>,
            <code class="constant">GL_UNSIGNED_INT_8_8_8_8_REV</code>,
            <code class="constant">GL_UNSIGNED_INT_10_10_10_2</code>, or
            <code class="constant">GL_UNSIGNED_INT_2_10_10_10_REV</code>
            and <em class="parameter"><code>format</code></em> is neither <code class="constant">GL_RGBA</code> nor <code class="constant">GL_BGRA</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>format</code></em> or <em class="parameter"><code>internalFormat</code></em> is
            <code class="constant">GL_DEPTH_COMPONENT</code>, <code class="constant">GL_DEPTH_COMPONENT16</code>,
            <code class="constant">GL_DEPTH_COMPONENT24</code>, or <code class="constant">GL_DEPTH_COMPONENT32</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be unpacked from the buffer
            object such that the memory reads required would exceed the data store size.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and <em class="parameter"><code>data</code></em> is not evenly divisible
            into the number of bytes needed to store in memory a datum indicated by <em class="parameter"><code>type</code></em>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
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
                  <code class="function">glTexImage3D</code>
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
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage3D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glGetCompressedTexImage"><span class="citerefentry"><span class="refentrytitle">glGetCompressedTexImage</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2011-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glTexImage3D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glTexImage3D glad_glTexImage3D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glTexSubImage3D'>OpenGL 4</a><br /><a  href='../gl3/glTexSubImage3D'>OpenGL 3</a><br /><a  href='../gl2/glTexSubImage3D'>OpenGL 2</a><br /><a  href='../es3/glTexSubImage3D'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glTexSubImage3D</h1>
    <div class="refentry" id="glTexSubImage3D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glTexSubImage3D, glTextureSubImage3D — specify a three-dimensional texture subimage</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTexSubImage3D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">zoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">depth</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">pixels</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTextureSubImage3D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">zoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">depth</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const void *<var class="pdparam">pixels</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target to which the texture is bound
                    for <code class="function">glTexSubImage3D</code>.
                    Must be <code class="constant">GL_TEXTURE_3D</code> or
                    <code class="constant">GL_TEXTURE_2D_ARRAY</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the texture object name for
                    <code class="function">glTextureSubImage3D</code>. The effective
                    target of <em class="parameter"><code>texture</code></em> must be one of
                    the valid <em class="parameter"><code>target</code></em> values above.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level <span class="emphasis"><em>n</em></span> is the <span class="emphasis"><em>n</em></span>th mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a texel offset in the x direction within the texture array.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>yoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a texel offset in the y direction within the texture array.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>zoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a texel offset in the z direction within the texture array.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture subimage.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the height of the texture subimage.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>depth</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the depth of the texture subimage.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>format</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the format of the pixel data.
                    The following symbolic values are accepted:
                    <code class="constant">GL_RED</code>,
                    <code class="constant">GL_RG</code>,
                    <code class="constant">GL_RGB</code>,
                    <code class="constant">GL_BGR</code>,
                    <code class="constant">GL_RGBA</code>,
                    <code class="constant">GL_DEPTH_COMPONENT</code>, and
                    <code class="constant">GL_STENCIL_INDEX</code>.
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
                    Specifies the data type of the pixel data.
                    The following symbolic values are accepted:
                    <code class="constant">GL_UNSIGNED_BYTE</code>,
                    <code class="constant">GL_BYTE</code>,
                    <code class="constant">GL_UNSIGNED_SHORT</code>,
                    <code class="constant">GL_SHORT</code>,
                    <code class="constant">GL_UNSIGNED_INT</code>,
                    <code class="constant">GL_INT</code>,
                    <code class="constant">GL_FLOAT</code>,
                    <code class="constant">GL_UNSIGNED_BYTE_3_3_2</code>,
                    <code class="constant">GL_UNSIGNED_BYTE_2_3_3_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_6_5</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_6_5_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_5_5_1</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_1_5_5_5_REV</code>,
                    <code class="constant">GL_UNSIGNED_INT_8_8_8_8</code>,
                    <code class="constant">GL_UNSIGNED_INT_8_8_8_8_REV</code>,
                    <code class="constant">GL_UNSIGNED_INT_10_10_10_2</code>, and
                    <code class="constant">GL_UNSIGNED_INT_2_10_10_10_REV</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pixels</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the image data in memory.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Texturing maps a portion of a specified texture image
            onto each graphical primitive for which texturing is enabled.
        </p>
        <p>
            <code class="function">glTexSubImage3D</code> and
            <code class="function">glTextureSubImage3D</code> redefine a contiguous
            subregion of an existing three-dimensional or two-dimensioanl
            array texture image.
            The texels referenced by <em class="parameter"><code>pixels</code></em> replace the portion of the
            existing texture array with x indices <em class="parameter"><code>xoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">width</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive,
            y indices <em class="parameter"><code>yoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">height</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive,
            and z indices <em class="parameter"><code>zoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">zoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">depth</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive.
            For three-dimensional textures, the z index refers to the third
            dimension. For two-dimensional array textures, the z index refers to
            the slice index.
            This region may not include any texels outside the range of the
            texture array as it was originally specified.
            It is not an error to specify a subtexture with zero width, height, or
            depth but such a specification has no effect.
        </p>
        <p>
            If a non-zero named buffer object is bound to the <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target
            (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is
            specified, <em class="parameter"><code>pixels</code></em> is treated as a byte offset into the buffer object's data store.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a> modes affect texture images.
        </p>
        <p>
            <code class="function">glTexSubImage3D</code> and
            <code class="function">glTextureSubImage3D</code> specify a
            three-dimensional or two-dimensional array subtexture for the
            current texture unit, specified with
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
        </p>
        <p>
            <code class="constant">GL_STENCIL_INDEX</code> is accepted for <em class="parameter"><code>format</code></em> only if the GL version
            is 4.4 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if
            <em class="parameter"><code>target</code></em> or the effective target of
            <em class="parameter"><code>texture</code></em> is not
            <code class="constant">GL_TEXTURE_3D</code> or
            <code class="constant">GL_TEXTURE_2D_ARRAY</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glTextureSubImage3D</code> if
            <em class="parameter"><code>texture</code></em> is not the name of an existing
            texture object.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>format</code></em> is not an accepted
            format constant.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>type</code></em> is not a type constant.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>level</code></em> is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> may be generated if <em class="parameter"><code>level</code></em> is greater
            than
            <math overflow="scroll">

                <msub><mi mathvariant="italic">log</mi>
                <mn>2</mn>
                </msub>
            </math>
            <span class="emphasis"><em>max</em></span>,
            where <span class="emphasis"><em>max</em></span> is the returned value of <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>&lt;</mo>
                    <mrow>
                        <mo>-</mo>
                        <mi mathvariant="italic">b</mi>
                    </mrow>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">xoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">width</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">w</mi>
                            <mo>-</mo>
                            <mi mathvariant="italic">b</mi>
                        </mrow>
                    </mfenced>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>&lt;</mo>
                    <mrow>
                        <mo>-</mo>
                        <mi mathvariant="italic">b</mi>
                    </mrow>
                </mrow>
            </math>,
            or
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">yoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">height</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">h</mi>
                            <mo>-</mo>
                            <mi mathvariant="italic">b</mi>
                        </mrow>
                    </mfenced>
                </mrow>
            </math>,
            or
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">zoffset</mi>
                    <mo>&lt;</mo>
                    <mrow>
                        <mo>-</mo>
                        <mi mathvariant="italic">b</mi>
                    </mrow>
                </mrow>
            </math>,
            or
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">zoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">depth</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">d</mi>
                            <mo>-</mo>
                            <mi mathvariant="italic">b</mi>
                        </mrow>
                    </mfenced>
                </mrow>
            </math>,
            where
            <math overflow="scroll"><mi mathvariant="italic">w</mi></math>
            is the <code class="constant">GL_TEXTURE_WIDTH</code>,
            <math overflow="scroll"><mi mathvariant="italic">h</mi></math>
            is the <code class="constant">GL_TEXTURE_HEIGHT</code>,
            <math overflow="scroll"><mi mathvariant="italic">d</mi></math>
            is the <code class="constant">GL_TEXTURE_DEPTH</code>
            and
            <math overflow="scroll"><mi mathvariant="italic">b</mi></math>
            is the border width of the texture image being modified.
            Note that
            <math overflow="scroll"><mi mathvariant="italic">w</mi></math>,
            <math overflow="scroll"><mi mathvariant="italic">h</mi></math>,
            and
            <math overflow="scroll"><mi mathvariant="italic">d</mi></math>
            include twice the border width.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>width</code></em>, <em class="parameter"><code>height</code></em>, or <em class="parameter"><code>depth</code></em>
            is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if the texture array has not
            been defined by a previous <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>
            or <a class="citerefentry" href="glTexStorage3D"><span class="citerefentry"><span class="refentrytitle">glTexStorage3D</span></span></a> operation.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>type</code></em> is one of
            <code class="constant">GL_UNSIGNED_BYTE_3_3_2</code>,
            <code class="constant">GL_UNSIGNED_BYTE_2_3_3_REV</code>,
            <code class="constant">GL_UNSIGNED_SHORT_5_6_5</code>, or
            <code class="constant">GL_UNSIGNED_SHORT_5_6_5_REV</code>
            and <em class="parameter"><code>format</code></em> is not <code class="constant">GL_RGB</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>type</code></em> is one of
            <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4</code>,
            <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4_REV</code>,
            <code class="constant">GL_UNSIGNED_SHORT_5_5_5_1</code>,
            <code class="constant">GL_UNSIGNED_SHORT_1_5_5_5_REV</code>,
            <code class="constant">GL_UNSIGNED_INT_8_8_8_8</code>,
            <code class="constant">GL_UNSIGNED_INT_8_8_8_8_REV</code>,
            <code class="constant">GL_UNSIGNED_INT_10_10_10_2</code>, or
            <code class="constant">GL_UNSIGNED_INT_2_10_10_10_REV</code>
            and <em class="parameter"><code>format</code></em> is neither <code class="constant">GL_RGBA</code> nor <code class="constant">GL_BGRA</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>format</code></em> is <code class="constant">GL_STENCIL_INDEX</code>
            and the base internal format is not <code class="constant">GL_STENCIL_INDEX</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be unpacked from the buffer
            object such that the memory reads required would exceed the data store size.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and <em class="parameter"><code>pixels</code></em> is not evenly divisible
            into the number of bytes needed to store in memory a datum indicated by <em class="parameter"><code>type</code></em>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
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
                  <code class="function">glTexSubImage3D</code>
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
                  <code class="function">glTextureSubImage3D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glTexSubImage3D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glTexSubImage3D glad_glTexSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCopyTexSubImage3D'>OpenGL 4</a><br /><a  href='../gl3/glCopyTexSubImage3D'>OpenGL 3</a><br /><a  href='../gl2/glCopyTexSubImage3D'>OpenGL 2</a><br /><a  href='../es3/glCopyTexSubImage3D'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glCopyTexSubImage3D</h1>
    <div class="refentry" id="glCopyTexSubImage3D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCopyTexSubImage3D, glCopyTextureSubImage3D — copy a three-dimensional texture subimage</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyTexSubImage3D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">zoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">x</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">y</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyTextureSubImage3D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">zoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">x</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">y</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the target to which the texture object is bound for
          <code class="function">glCopyTexSubImage3D</code> function. Must be
          <code class="constant">GL_TEXTURE_3D</code> or
          <code class="constant">GL_TEXTURE_2D_ARRAY</code>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the texture object name for
          <code class="function">glCopyTextureSubImage3D</code> function.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the level-of-detail number. Level 0 is the base
          image level. Level <span class="emphasis"><em>n</em></span> is the
          <span class="emphasis"><em>n</em></span>th mipmap reduction image.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the x direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>yoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the y direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>zoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the z direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term"><em class="parameter"><code>x</code></em>, </span>
              <span class="term">
                <em class="parameter">
                  <code>y</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specify the window coordinates of the lower left corner of the
          rectangular region of pixels to be copied.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the width of the texture subimage.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the height of the texture subimage.</p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p><code class="function">glCopyTexSubImage3D</code> and
    <code class="function">glCopyTextureSubImage3D</code> functions replace a rectangular portion of a three-dimensional
            or two-dimensional array texture image with pixels from the current <code class="constant">GL_READ_BUFFER</code> (rather
            than from Main memory, as is the case for <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>).
        </p>
        <p>
            The screen-aligned pixel rectangle with lower left corner at
            (<em class="parameter"><code>x</code></em>, <em class="parameter"><code>y</code></em>) and with
            width <em class="parameter"><code>width</code></em> and height <em class="parameter"><code>height</code></em> replaces the portion of the
            texture array with x indices <em class="parameter"><code>xoffset</code></em> through
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">width</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive, and y indices <em class="parameter"><code>yoffset</code></em> through
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">height</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive, at z index <em class="parameter"><code>zoffset</code></em> and at the mipmap level specified by <em class="parameter"><code>level</code></em>.
        </p>
        <p>
            The pixels in the rectangle are processed exactly as if
            <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a> had been called, but the process stops just before
            final conversion.
            At this point, all pixel component values are clamped to the range
            <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mn>0</mn>
                    <mn>1</mn>
                </mfenced>
            </math>
            and then converted to the texture's internal format for storage in the texel
            array.
        </p>
        <p>
            The destination rectangle in the texture array may not include any texels
            outside the texture array as it was originally specified.
            It is not an error to specify a subtexture with zero width or height, but
            such a specification has no effect.
        </p>
        <p>
            If any of the pixels within the specified rectangle of the current
            <code class="constant">GL_READ_BUFFER</code> are outside the read window associated with the current
            rendering context, then the values obtained for those pixels are undefined.
        </p>
        <p>
            No change is made to the <span class="emphasis"><em>internalformat</em></span>, <span class="emphasis"><em>width</em></span>,
            <span class="emphasis"><em>height</em></span>, <span class="emphasis"><em>depth</em></span>, or <span class="emphasis"><em>border</em></span> parameters of the specified texture
            array or to texel values outside the specified subregion.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a> modes affect texture images.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p><code class="constant">GL_INVALID_ENUM</code> is generated by
    <code class="function">glCopyTexSubImage3D</code> if <em class="parameter"><code>target</code></em>
    is not <code class="constant">GL_TEXTURE_3D</code>,
    <code class="constant">GL_TEXTURE_2D_ARRAY</code> or
    <code class="constant">GL_TEXTURE_CUBE_MAP_ARRAY</code>.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glCopyTextureSubImage3D</code> if the effective target is
    not <code class="constant">GL_TEXTURE_3D</code>,
    <code class="constant">GL_TEXTURE_2D_ARRAY</code>,
    <code class="constant">GL_TEXTURE_CUBE_MAP_ARRAY</code> or
    <code class="constant">GL_TEXTURE_CUBE_MAP</code>.</p>
        <p><code class="constant">GL_INVALID_FRAMEBUFFER_OPERATION</code> is generated
    if the object bound to <code class="constant">GL_READ_FRAMEBUFFER_BINDING</code> is
    not framebuffer complete.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if the
    texture array has not been defined by a previous <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a> or <a class="citerefentry" href="glTexStorage3D"><span class="citerefentry"><span class="refentrytitle">glTexStorage3D</span></span></a> operation.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glCopyTextureSubImage3D</code> if
    <em class="parameter"><code>texture</code></em> is not the name of an existing texture
    object.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>level</code></em> is less than 0.</p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> may be generated if
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">level</mi>
                    <mo>&gt;</mo>
                    <mrow>
                        <msub><mi mathvariant="italic">log</mi>
                        <mn>2</mn>
                        </msub>
                        <mo>⁡</mo>
                        <mfenced open="(" close=")">
                            <mi mathvariant="italic">max</mi>
                        </mfenced>
                    </mrow>
                </mrow>
            </math>,
            where
            <math overflow="scroll"><mi mathvariant="italic">max</mi></math>
            is the returned value of <code class="constant">GL_MAX_3D_TEXTURE_SIZE</code> if <em class="parameter"><code>target</code></em>
            is <code class="constant">GL_TEXTURE_3D</code> or the returned value of <code class="constant">GL_MAX_ARRAY_TEXTURE_LAYERS</code>
            if <em class="parameter"><code>target</code></em> is <code class="constant">GL_TEXTURE_2D_ARRAY</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>&lt;</mo>
                    <mn>0</mn>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">xoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">width</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mi mathvariant="italic">w</mi>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>&lt;</mo>
                    <mn>0</mn>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">yoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">height</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mi mathvariant="italic">h</mi>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">zoffset</mi>
                    <mo>&lt;</mo>
                    <mn>0</mn>
                </mrow>
            </math>,
            or
            <math overflow="scroll">

                <mrow>
                     <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">zoffset</mi>
                            <mo>+</mo>
                            <mn>1</mn>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mi mathvariant="italic">d</mi>
                </mrow>
            </math>,
            where
            <math overflow="scroll"><mi mathvariant="italic">w</mi></math>
            is the <code class="constant">GL_TEXTURE_WIDTH</code>,
            <math overflow="scroll"><mi mathvariant="italic">h</mi></math>
            is the <code class="constant">GL_TEXTURE_HEIGHT</code>,
            <math overflow="scroll"><mi mathvariant="italic">d</mi></math>
            is the <code class="constant">GL_TEXTURE_DEPTH</code> and
            of the texture image being modified.
            Note that
            <math overflow="scroll"><mi mathvariant="italic">w</mi></math>,
            <math overflow="scroll"><mi mathvariant="italic">h</mi></math>,
            and
            <math overflow="scroll"><mi mathvariant="italic">d</mi></math>
            include twice the border width.
        </p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated
    if:</p>
        <div class="itemizedlist">
          <ul class="itemizedlist" style="list-style-type: disc; ">
            <li class="listitem">
              <p>the read buffer is <code class="constant">GL_NONE</code>, or</p>
            </li>
            <li class="listitem">
              <p>the value of <code class="constant">GL_READ_FRAMEBUFFER_BINDING</code>
          is non-zero, and:</p>
              <div class="itemizedlist">
                <ul class="itemizedlist" style="list-style-type: circle; ">
                  <li class="listitem">
                    <p>the read buffer selects an attachment that has no image
                attached, or</p>
                  </li>
                  <li class="listitem">
                    <p>the effective value of
                <code class="constant">GL_SAMPLE_BUFFERS</code> for the read
                framebuffer is one.</p>
                  </li>
                </ul>
              </div>
            </li>
          </ul>
        </div>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
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
                  <code class="function">glCopyTexSubImage3D</code>
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
                  <code class="function">glCopyTextureSubImage3D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glReadBuffer"><span class="citerefentry"><span class="refentrytitle">glReadBuffer</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006
            Silicon Graphics, Inc.
            Copyright © 2012-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCopyTexSubImage3D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glCopyTexSubImage3D glad_glCopyTexSubImage3D
#endif
#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
GLAPI int GLAD_GL_VERSION_1_3;
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
GLAPI PFNGLACTIVETEXTUREPROC glad_glActiveTexture;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glActiveTexture'>OpenGL 4</a><br /><a  href='../gl3/glActiveTexture'>OpenGL 3</a><br /><a  href='../gl2/glActiveTexture'>OpenGL 2</a><br /><a  href='../es3/glActiveTexture'>OpenGL ES 3</a><br /><a  href='../es2/glActiveTexture'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glActiveTexture</h1>
    <div class="refentry" id="glActiveTexture">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glActiveTexture — select active texture unit</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glActiveTexture</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">texture</var><code>)</code>;</td>
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
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies which texture unit to make active. The number
                    of texture units is implementation dependent, but must
                    be at least 80. <em class="parameter"><code>texture</code></em> must be
                    one of
                    <code class="constant">GL_TEXTURE</code><span class="emphasis"><em>i</em></span>,
                    where <span class="emphasis"><em>i</em></span> ranges from zero to the value
                    of
                    <code class="constant">GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS</code>
                    minus one. The initial value is
                    <code class="constant">GL_TEXTURE0</code>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glActiveTexture</code> selects which texture unit subsequent texture state calls will
            affect.  The number of texture units an implementation supports is
            implementation dependent, but must be at least 80.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if
            <em class="parameter"><code>texture</code></em> is not one of
            <code class="constant">GL_TEXTURE</code><span class="emphasis"><em>i</em></span>, where
            <span class="emphasis"><em>i</em></span> ranges from zero to the value of
            <code class="constant">GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS</code> minus
            one.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_ACTIVE_TEXTURE</code>, or <code class="constant">GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS</code>.
        </p>
      </div>
      <div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://antongerdelan.net/opengl/cubemaps.html">Anton Gerdelan - Cube Maps: Sky Boxes and Environment Mapping</a><br /><a href="https://open.gl/textures">open.gl - Textures Objects and Parameters</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-13-normal-mapping/">opengl-tutorial.org - Tutorial 13 : Normal Mapping</a><br /></p></div>
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
                  <code class="function">glActiveTexture</code>
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
            <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a>,
            <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage3D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glDeleteTextures"><span class="citerefentry"><span class="refentrytitle">glDeleteTextures</span></span></a>
            <a class="citerefentry" href="glIsTexture"><span class="citerefentry"><span class="refentrytitle">glIsTexture</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage2DMultisample"><span class="citerefentry"><span class="refentrytitle">glTexImage2DMultisample</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexImage3DMultisample"><span class="citerefentry"><span class="refentrytitle">glTexImage3DMultisample</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>,
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glActiveTexture.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glActiveTexture glad_glActiveTexture
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
GLAPI PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glSampleCoverage'>OpenGL 4</a><br /><a  href='../gl3/glSampleCoverage'>OpenGL 3</a><br /><a  href='../gl2/glSampleCoverage'>OpenGL 2</a><br /><a  href='../es3/glSampleCoverage'>OpenGL ES 3</a><br /><a  href='../es2/glSampleCoverage'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glSampleCoverage</h1>
    <div class="refentry" id="glSampleCoverage">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glSampleCoverage — specify multisample coverage parameters</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glSampleCoverage</strong>(</code>
              </td>
              <td>GLfloat <var class="pdparam">value</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLboolean <var class="pdparam">invert</var><code>)</code>;</td>
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
                  <code>value</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specify a single floating-point sample coverage value.  The value is
                    clamped to the range
                    <math overflow="scroll">

                        <mfenced open="[" close="]">
                            <mn>0</mn>
                            <mn>1</mn>
                        </mfenced>
                    </math>.
                    The initial value is 1.0.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>invert</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specify a single boolean value representing if the coverage masks should be
                    inverted.  <code class="constant">GL_TRUE</code> and <code class="constant">GL_FALSE</code> are accepted.  The initial value
                    is <code class="constant">GL_FALSE</code>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Multisampling samples a pixel multiple times at various
            implementation-dependent subpixel locations to generate antialiasing
            effects.  Multisampling transparently antialiases points, lines, polygons,
            and images if it is enabled.
        </p>
        <p>
            <em class="parameter"><code>value</code></em> is used in constructing a temporary mask used in determining which
            samples will be used in resolving the final fragment color.  This mask is
            bitwise-anded with the coverage mask generated from the multisampling
            computation.  If the <em class="parameter"><code>invert</code></em> flag is set, the temporary mask is inverted
            (all bits flipped) and then the bitwise-and is computed.
        </p>
        <p>
            If an implementation does not have any multisample buffers available, or
            multisampling is disabled, rasterization occurs with only a single sample
            computing a pixel's final RGB color.
        </p>
        <p>
            Provided an implementation supports multisample buffers, and multisampling
            is enabled, then a pixel's final color is generated by combining several
            samples per pixel.  Each sample contains color, depth, and stencil
            information, allowing those operations to be performed on each sample.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The type of the <em class="parameter"><code>value</code></em> parameter was
            changed from GLclampf to GLfloat. This change is transparent
            to user code and is described in detail on the
            <a class="citerefentry" href="removedTypes"><span class="citerefentry"><span class="refentrytitle">removedTypes</span></span></a>
            page.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_SAMPLE_COVERAGE_VALUE</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_SAMPLE_COVERAGE_INVERT</code>
        </p>
        <p>
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a> with argument <code class="constant">GL_MULTISAMPLE</code>
        </p>
        <p>
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a> with argument <code class="constant">GL_SAMPLE_ALPHA_TO_COVERAGE</code>
        </p>
        <p>
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a> with argument <code class="constant">GL_SAMPLE_ALPHA_TO_ONE</code>
        </p>
        <p>
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a> with argument <code class="constant">GL_SAMPLE_COVERAGE</code>
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
                  <code class="function">glSampleCoverage</code>
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
            <a class="citerefentry" href="glEnable"><span class="citerefentry"><span class="refentrytitle">glEnable</span></span></a>,
            <a class="citerefentry" href="glSampleMaski"><span class="citerefentry"><span class="refentrytitle">glSampleMaski</span></span></a>,
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glSampleCoverage.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glSampleCoverage glad_glSampleCoverage
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCompressedTexImage3D'>OpenGL 4</a><br /><a  href='../gl3/glCompressedTexImage3D'>OpenGL 3</a><br /><a  href='../gl2/glCompressedTexImage3D'>OpenGL 2</a><br /><a  href='../es3/glCompressedTexImage3D'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glCompressedTexImage3D</h1>
    <div class="refentry" id="glCompressedTexImage3D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCompressedTexImage3D — specify a three-dimensional texture image in a compressed format</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTexImage3D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">internalformat</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">depth</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">border</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">data</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target texture.
                    Must be <code class="constant">GL_TEXTURE_3D</code>, <code class="constant">GL_PROXY_TEXTURE_3D</code>,
                    <code class="constant">GL_TEXTURE_2D_ARRAY</code> or <code class="constant">GL_PROXY_TEXTURE_2D_ARRAY</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level <span class="emphasis"><em>n</em></span> is the <span class="emphasis"><em>n</em></span>th mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>internalformat</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the format of the compressed image data stored at address <em class="parameter"><code>data</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture image.
                    All implementations support 3D texture images that are at least 16 texels wide.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the height of the texture image.
                    All implementations support 3D texture images that are at least 16 texels
                    high.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>depth</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the depth of the texture image.
                    All implementations support 3D texture images that are at least 16 texels
                    deep.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>border</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    This value must be 0.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>imageSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of unsigned bytes of image data starting at the
                    address specified by <em class="parameter"><code>data</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>data</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the compressed image data in memory.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Texturing allows elements of an image array to be read by shaders.
        </p>
        <p>
            <code class="function">glCompressedTexImage3D</code> loads a previously defined, and retrieved, compressed three-dimensional
            texture image if <em class="parameter"><code>target</code></em> is <code class="constant">GL_TEXTURE_3D</code> (see <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>).
        </p>
        <p>
            If <em class="parameter"><code>target</code></em> is <code class="constant">GL_TEXTURE_2D_ARRAY</code>, <em class="parameter"><code>data</code></em> is
            treated as an array of compressed 2D textures.
        </p>
        <p>
            If <em class="parameter"><code>target</code></em> is <code class="constant">GL_PROXY_TEXTURE_3D</code> or <code class="constant">GL_PROXY_TEXTURE_2D_ARRAY</code>,
            no data is read from <em class="parameter"><code>data</code></em>, but
            all of the texture image state is recalculated, checked for consistency,
            and checked against the implementation's capabilities.  If the
            implementation cannot handle a texture of the requested texture size, it
            sets all of the image state to 0, but does not generate an error (see
            <a class="citerefentry" href="glGetError"><span class="citerefentry"><span class="refentrytitle">glGetError</span></span></a>). To query for an entire mipmap array, use an image array level
            greater than or equal to 1.
        </p>
        <p>
            <em class="parameter"><code>internalformat</code></em> must be a known compressed image format (such as <code class="constant">GL_RGTC</code>)
            or an extension-specified compressed-texture format.
            When a texture is loaded with <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a> using a generic compressed
            texture format (e.g., <code class="constant">GL_COMPRESSED_RGB</code>), the GL selects from one of
            its extensions supporting compressed textures.  In order to load the
            compressed texture image using <code class="function">glCompressedTexImage3D</code>, query the compressed texture image's
            size and format using <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>.
        </p>
        <p>
            If a non-zero named buffer object is bound to the <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target
            (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is
            specified, <em class="parameter"><code>data</code></em> is treated as a byte offset into the buffer object's data store.
        </p>
        <p>
            If the compressed data are arranged into fixed-size blocks of texels, the pixel
            storage modes can be used to select a sub-rectangle from a larger containing rectangle.
            These pixel storage modes operate in the same way as they do for <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>.
            In the following description, denote by
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>, and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math>
            the values of pixel storage modes <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_SIZE</code>,
            <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_WIDTH</code>, <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_HEIGHT</code>,
            and <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_DEPTH</code>, respectively.
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math>
            is the compressed block size in bytes;
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>,
            and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math>
            are the compressed block width, height, and depth in pixels.
        </p>
        <p>
            By default the pixel storage modes <code class="constant">GL_UNPACK_ROW_LENGTH</code>,
            <code class="constant">GL_UNPACK_SKIP_ROWS</code>, <code class="constant">GL_UNPACK_SKIP_PIXELS</code>,
            <code class="constant">GL_UNPACK_IMAGE_HEIGHT</code> and <code class="constant">GL_UNPACK_SKIP_IMAGES</code>
            are ignored for compressed images. To enable <code class="constant">GL_UNPACK_SKIP_PIXELS</code>
            and <code class="constant">GL_UNPACK_ROW_LENGTH</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math>
            and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>
            must both be non-zero.
            To also enable <code class="constant">GL_UNPACK_SKIP_ROWS</code> and <code class="constant">GL_UNPACK_IMAGE_HEIGHT</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>
            must be non-zero.
            To also enable <code class="constant">GL_UNPACK_SKIP_IMAGES</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math>
            must be non-zero. All parameters must be consistent with the compressed format to produce the desired results.
        </p>
        <p>
            When selecting a sub-rectangle from a compressed image:
            </p>
        <div class="itemizedlist">
          <ul class="itemizedlist" style="list-style-type: disc; ">
            <li class="listitem">
              <p>
                        the value of <code class="constant">GL_UNPACK_SKIP_PIXELS</code> must be a multiple of
                        <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>;
                    </p>
            </li>
            <li class="listitem">
              <p>
                        the value of <code class="constant">GL_UNPACK_SKIP_ROWS</code> must be a multiple of
                        <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>;
                    </p>
            </li>
            <li class="listitem">
              <p>
                        the value of <code class="constant">GL_UNPACK_SKIP_IMAGES</code> must be a multiple of
                        <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>.
                    </p>
            </li>
          </ul>
        </div>
        <p>
        </p>
        <p>
            <em class="parameter"><code>imageSize</code></em> must be equal to:
        </p>
        <p>
            <math display="block" overflow="scroll">
                  <mrow>
                    <msub>
                      <mi>b</mi>
                      <mi>s</mi>
                    </msub>
                    <mo lspace="2px" rspace="2px">×</mo>
                    <mfenced open="⌈" close="⌉">
                      <mfrac>
                        <mi>width</mi>
                        <msub>
                          <mi>b</mi>
                          <mi>w</mi>
                        </msub>
                      </mfrac>
                    </mfenced>
                    <mo lspace="2px" rspace="2px">×</mo>
                    <mfenced open="⌈" close="⌉">
                      <mfrac>
                        <mi>height</mi>
                        <msub>
                          <mi>b</mi>
                          <mi>h</mi>
                        </msub>
                      </mfrac>
                    </mfenced>
                    <mo lspace="2px" rspace="2px">×</mo>
                    <mfenced open="⌈" close="⌉">
                      <mfrac>
                        <mi>depth</mi>
                        <msub>
                          <mi>b</mi>
                          <mi>d</mi>
                        </msub>
                      </mfrac>
                    </mfenced>
                  </mrow>
                </math>
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
          <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>internalformat</code></em> is not one of the generic
          compressed internal formats:
          <code class="constant">GL_COMPRESSED_RED</code>,
          <code class="constant">GL_COMPRESSED_RG</code>,
          <code class="constant">GL_COMPRESSED_RGB</code>,
          <code class="constant">GL_COMPRESSED_RGBA</code>.
          <code class="constant">GL_COMPRESSED_SRGB</code>, or
          <code class="constant">GL_COMPRESSED_SRGB_ALPHA</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>imageSize</code></em> is not consistent with
            the format, dimensions, and contents of the specified compressed image data.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>border</code></em> is not 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if parameter combinations are not
            supported by the specific compressed internal format as specified in the
            specific texture compression extension.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be unpacked from the buffer
            object such that the memory reads required would exceed the data store size.
        </p>
        <p>
            Undefined results, including abnormal program termination, are generated if <em class="parameter"><code>data</code></em> is not encoded in a manner consistent with the extension specification defining the internal compression format.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetCompressedTexImage"><span class="citerefentry"><span class="refentrytitle">glGetCompressedTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_TEXTURE_COMPRESSED</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
        </p>
        <p>
            <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with arguments <code class="constant">GL_TEXTURE_INTERNAL_FORMAT</code>
            and <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code>
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
                  <code class="function">glCompressedTexImage3D</code>
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
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2011-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCompressedTexImage3D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glCompressedTexImage3D glad_glCompressedTexImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCompressedTexImage2D'>OpenGL 4</a><br /><a  href='../gl3/glCompressedTexImage2D'>OpenGL 3</a><br /><a  href='../gl2/glCompressedTexImage2D'>OpenGL 2</a><br /><a  href='../es3/glCompressedTexImage2D'>OpenGL ES 3</a><br /><a  href='../es2/glCompressedTexImage2D'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glCompressedTexImage2D</h1>
    <div class="refentry" id="glCompressedTexImage2D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCompressedTexImage2D — specify a two-dimensional texture image in a compressed format</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTexImage2D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">internalformat</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">border</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">data</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target texture.
                    Must be <code class="constant">GL_TEXTURE_2D</code>, <code class="constant">GL_PROXY_TEXTURE_2D</code>,
                    <code class="constant">GL_TEXTURE_1D_ARRAY</code>, <code class="constant">GL_PROXY_TEXTURE_1D_ARRAY</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>, or
                    <code class="constant">GL_PROXY_TEXTURE_CUBE_MAP</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level <span class="emphasis"><em>n</em></span> is the <span class="emphasis"><em>n</em></span>th mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>internalformat</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the format of the compressed image data stored at address <em class="parameter"><code>data</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture image.
                    All implementations support 2D texture and cube map texture images that are at least 16384 texels wide.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the height of the texture image.
                    All implementations support 2D texture and cube map texture images that are at least 16384 texels high.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>border</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    This value must be 0.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>imageSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of unsigned bytes of image data starting at the
                    address specified by <em class="parameter"><code>data</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>data</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the compressed image data in memory.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Texturing allows elements of an image array to be read by shaders.
        </p>
        <p>
            <code class="function">glCompressedTexImage2D</code> loads a previously defined, and retrieved, compressed two-dimensional
            texture image if <em class="parameter"><code>target</code></em> is <code class="constant">GL_TEXTURE_2D</code>, or one of the
            cube map faces such as <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>.
            (see <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>).
        </p>
        <p>
            If <em class="parameter"><code>target</code></em> is <code class="constant">GL_TEXTURE_1D_ARRAY</code>, <em class="parameter"><code>data</code></em>
            is treated as an array of compressed 1D textures.
        </p>
        <p>
            If <em class="parameter"><code>target</code></em> is <code class="constant">GL_PROXY_TEXTURE_2D</code>, <code class="constant">GL_PROXY_TEXTURE_1D_ARRAY</code>
            or <code class="constant">GL_PROXY_TEXTURE_CUBE_MAP</code>, no data is read from <em class="parameter"><code>data</code></em>, but
            all of the texture image state is recalculated, checked for consistency,
            and checked against the implementation's capabilities.  If the
            implementation cannot handle a texture of the requested texture size, it
            sets all of the image state to 0, but does not generate an error (see
            <a class="citerefentry" href="glGetError"><span class="citerefentry"><span class="refentrytitle">glGetError</span></span></a>). To query for an entire mipmap array,
            use an image array level greater than or equal to 1.
        </p>
        <p>
            <em class="parameter"><code>internalformat</code></em> must be a known compressed image format (such as <code class="constant">GL_RGTC</code>)
            or an extension-specified compressed-texture format.
            When a texture is loaded with <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a> using a generic compressed
            texture format (e.g., <code class="constant">GL_COMPRESSED_RGB</code>), the GL selects from one of
            its extensions supporting compressed textures.  In order to load the
            compressed texture image using <code class="function">glCompressedTexImage2D</code>, query the compressed texture image's
            size and format using <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>.
        </p>
        <p>
            If a non-zero named buffer object is bound to the <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target
            (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is
            specified, <em class="parameter"><code>data</code></em> is treated as a byte offset into the buffer object's data store.
        </p>
        <p>
            If the compressed data are arranged into fixed-size blocks of texels, the pixel
            storage modes can be used to select a sub-rectangle from a larger containing rectangle.
            These pixel storage modes operate in the same way as they do for <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
            In the following description, denote by
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>, and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math>,
            the values of pixel storage modes <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_SIZE</code>,
            <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_WIDTH</code>, <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_HEIGHT</code>,
            and <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_DEPTH</code>, respectively.
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math> is the compressed block size in bytes;
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>, and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math> are the compressed block width, height, and depth in pixels.
        </p>
        <p>
            By default the pixel storage modes <code class="constant">GL_UNPACK_ROW_LENGTH</code>,
            <code class="constant">GL_UNPACK_SKIP_ROWS</code>, <code class="constant">GL_UNPACK_SKIP_PIXELS</code>,
            <code class="constant">GL_UNPACK_IMAGE_HEIGHT</code> and <code class="constant">GL_UNPACK_SKIP_IMAGES</code>
            are ignored for compressed images. To enable <code class="constant">GL_UNPACK_SKIP_PIXELS</code>
            and <code class="constant">GL_UNPACK_ROW_LENGTH</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math>
            and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>
            must both be non-zero.
            To also enable <code class="constant">GL_UNPACK_SKIP_ROWS</code> and <code class="constant">GL_UNPACK_IMAGE_HEIGHT</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>
            must be non-zero.
            To also enable <code class="constant">GL_UNPACK_SKIP_IMAGES</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math>
            must be non-zero. All parameters must be consistent with the compressed format to produce the desired results.
        </p>
        <p>
            When selecting a sub-rectangle from a compressed image:
            </p>
        <div class="itemizedlist">
          <ul class="itemizedlist" style="list-style-type: disc; ">
            <li class="listitem">
              <p>
                        The value of
                        <code class="constant">GL_UNPACK_SKIP_PIXELS</code> must be a
                        multiple of
                        <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>;
                    </p>
            </li>
            <li class="listitem">
              <p>
                        the value of
                        <code class="constant">GL_UNPACK_SKIP_ROWS</code> must be a
                        multiple of
                        <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>.
                    </p>
            </li>
          </ul>
        </div>
        <p>
        </p>
        <p>
            <em class="parameter"><code>imageSize</code></em> must be equal to:
        </p>
        <p>
            <math display="block" overflow="scroll">
                  <mrow>
                    <msub>
                      <mi>b</mi>
                      <mi>s</mi>
                    </msub>
                    <mo lspace="2px" rspace="2px">×</mo>
                    <mfenced open="⌈" close="⌉">
                      <mfrac>
                        <mi>width</mi>
                        <msub>
                          <mi>b</mi>
                          <mi>w</mi>
                        </msub>
                      </mfrac>
                    </mfenced>
                    <mo lspace="2px" rspace="2px">×</mo>
                    <mfenced open="⌈" close="⌉">
                      <mfrac>
                        <mi>height</mi>
                        <msub>
                          <mi>b</mi>
                          <mi>h</mi>
                        </msub>
                      </mfrac>
                    </mfenced>
                  </mrow>
                </math>
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The specific compressed internal formats <code class="constant">GL_COMPRESSED_RGB8_ETC2</code>,
          <code class="constant">GL_COMPRESSED_SRGB8_ETC2</code>,
          <code class="constant">GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2</code>,
          <code class="constant">GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2</code>,
          <code class="constant">GL_COMPRESSED_RGBA8_ETC2_EAC</code>,
          <code class="constant">GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC</code>,
          <code class="constant">GL_COMPRESSED_R11_EAC</code>,
          <code class="constant">GL_COMPRESSED_SIGNED_R11_EAC</code>,
          <code class="constant">GL_COMPRESSED_RG11_EAC</code>, and
          <code class="constant">GL_COMPRESSED_SIGNED_RG11_EAC</code> are available only if the GL version
          is 4.3 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
          <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>internalformat</code></em> is not one of the specific
          compressed internal formats:
          <code class="constant">GL_COMPRESSED_RED_RGTC1</code>,
          <code class="constant">GL_COMPRESSED_SIGNED_RED_RGTC1</code>,
          <code class="constant">GL_COMPRESSED_RG_RGTC2</code>,
          <code class="constant">GL_COMPRESSED_SIGNED_RG_RGTC2</code>.
          <code class="constant">GL_COMPRESSED_RGBA_BPTC_UNORM</code>,
          <code class="constant">GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM</code>,
          <code class="constant">GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT</code>,
          <code class="constant">GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT</code>,
          <code class="constant">GL_COMPRESSED_RGB8_ETC2</code>,
          <code class="constant">GL_COMPRESSED_SRGB8_ETC2</code>,
          <code class="constant">GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2</code>,
          <code class="constant">GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2</code>,
          <code class="constant">GL_COMPRESSED_RGBA8_ETC2_EAC</code>,
          <code class="constant">GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC</code>,
          <code class="constant">GL_COMPRESSED_R11_EAC</code>,
          <code class="constant">GL_COMPRESSED_SIGNED_R11_EAC</code>,
          <code class="constant">GL_COMPRESSED_RG11_EAC</code>, or
          <code class="constant">GL_COMPRESSED_SIGNED_RG11_EAC</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>imageSize</code></em> is not consistent with
            the format, dimensions, and contents of the specified compressed image
            data.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>border</code></em> is not 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if parameter combinations are not
            supported by the specific compressed internal format as specified in the
            specific texture compression extension.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be unpacked from the buffer
            object such that the memory reads required would exceed the data store size.
        </p>
        <p>
            Undefined results, including abnormal program termination, are generated if
            <em class="parameter"><code>data</code></em> is not encoded in a manner consistent with the extension
            specification defining the internal compression format.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetCompressedTexImage"><span class="citerefentry"><span class="refentrytitle">glGetCompressedTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_TEXTURE_COMPRESSED</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
        </p>
        <p>
            <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with arguments <code class="constant">GL_TEXTURE_INTERNAL_FORMAT</code>
            and <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code>
        </p>
      </div>
      <div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://www.oldunreal.com/editing/s3tc/ARB_texture_compression.pdf">S&eacute;bastien Domin&eacute; - Using Texture Compression in OpenGL</a><br /><a href="https://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/">opengl-tutorial.org - Tutorial 5 : A Textured Cube</a><br /></p></div>
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
                  <code class="function">glCompressedTexImage2D</code>
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
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage3D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2011-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCompressedTexImage2D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glCompressedTexImage2D glad_glCompressedTexImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCompressedTexImage1D'>OpenGL 4</a><br /><a  href='../gl3/glCompressedTexImage1D'>OpenGL 3</a><br /><a  href='../gl2/glCompressedTexImage1D'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glCompressedTexImage1D</h1>
    <div class="refentry" id="glCompressedTexImage1D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCompressedTexImage1D — specify a one-dimensional texture image in a compressed format</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTexImage1D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">internalformat</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">border</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">data</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target texture.
                    Must be <code class="constant">GL_TEXTURE_1D</code> or <code class="constant">GL_PROXY_TEXTURE_1D</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level <span class="emphasis"><em>n</em></span> is the <span class="emphasis"><em>n</em></span>th mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>internalformat</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the format of the compressed image data stored at address <em class="parameter"><code>data</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture image.
                    All implementations support texture images that are at least 64 texels wide. The height of the 1D texture image is 1.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>border</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    This value must be 0.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>imageSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of unsigned bytes of image data starting at the address specified by <em class="parameter"><code>data</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>data</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the compressed image data in memory.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Texturing allows elements of an image array to be read by shaders.
        </p>
        <p>
            <code class="function">glCompressedTexImage1D</code> loads a previously defined, and retrieved, compressed
            one-dimensional texture image if <em class="parameter"><code>target</code></em> is <code class="constant">GL_TEXTURE_1D</code>
            (see <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>).
        </p>
        <p>
            If <em class="parameter"><code>target</code></em> is <code class="constant">GL_PROXY_TEXTURE_1D</code>, no data is read from <em class="parameter"><code>data</code></em>, but
            all of the texture image state is recalculated, checked for consistency, and checked against the implementation's capabilities.  If the implementation cannot handle a texture of the requested texture size, it sets all of the image state to 0, but does not generate an error (see <a class="citerefentry" href="glGetError"><span class="citerefentry"><span class="refentrytitle">glGetError</span></span></a>). To query for an entire mipmap array, use an image array level greater than or equal to 1.
        </p>
        <p>
            <em class="parameter"><code>internalformat</code></em> must be an extension-specified compressed-texture format.
            When a texture is loaded with
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a> using a generic compressed  texture format
            (e.g., <code class="constant">GL_COMPRESSED_RGB</code>) the GL selects from one of
            its extensions supporting compressed textures.  In order to load the
            compressed texture image using <code class="function">glCompressedTexImage1D</code>, query the compressed texture image's size and
            format using <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>.
        </p>
        <p>
            If a non-zero named buffer object is bound to the <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target
            (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is
            specified, <em class="parameter"><code>data</code></em> is treated as a byte offset into the buffer object's data store.
        </p>
        <p>
            If the compressed data are arranged into fixed-size blocks of texels, the pixel
            storage modes can be used to select a sub-rectangle from a larger containing rectangle.
            These pixel storage modes operate in the same way as they do for <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>.
            In the following description, denote by
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>, and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math>
            the values of pixel storage modes <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_SIZE</code>,
            <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_WIDTH</code>, <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_HEIGHT</code>,
            and <code class="constant">GL_UNPACK_COMPRESSED_BLOCK_DEPTH</code>, respectively.
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math>
            is the compressed block size in bytes;
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>, and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math>
            are the compressed block width, height, and depth in pixels.
        </p>
        <p>
            By default the pixel storage modes <code class="constant">GL_UNPACK_ROW_LENGTH</code>,
            <code class="constant">GL_UNPACK_SKIP_ROWS</code>, <code class="constant">GL_UNPACK_SKIP_PIXELS</code>,
            <code class="constant">GL_UNPACK_IMAGE_HEIGHT</code> and <code class="constant">GL_UNPACK_SKIP_IMAGES</code>
            are ignored for compressed images. To enable <code class="constant">GL_UNPACK_SKIP_PIXELS</code>
            and <code class="constant">GL_UNPACK_ROW_LENGTH</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>s</mi></msub></mrow></math>
            and
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>
            must both be non-zero.
            To also enable <code class="constant">GL_UNPACK_SKIP_ROWS</code> and <code class="constant">GL_UNPACK_IMAGE_HEIGHT</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>h</mi></msub></mrow></math>
            must be non-zero.
            To also enable <code class="constant">GL_UNPACK_SKIP_IMAGES</code>,
            <math overflow="scroll"><mrow><msub><mi>b</mi><mi>d</mi></msub></mrow></math>
            must be non-zero. All parameters must be consistent with the compressed format to produce the desired results.
        </p>
        <p>
            When selecting a sub-rectangle from a compressed image,
            </p>
        <div class="itemizedlist">
          <ul class="itemizedlist" style="list-style-type: disc; ">
            <li class="listitem">
              <p>
                        the value of <code class="constant">GL_UNPACK_SKIP_PIXELS</code> must be a multiple of
                        <math overflow="scroll"><mrow><msub><mi>b</mi><mi>w</mi></msub></mrow></math>
                    </p>
            </li>
          </ul>
        </div>
        <p>
        </p>
        <p>
            <em class="parameter"><code>imageSize</code></em> must be equal to:
        </p>
        <p>
            <math display="block" overflow="scroll">
                  <mrow>
                    <msub>
                      <mi>b</mi>
                      <mi>s</mi>
                    </msub>
                    <mo lspace="2px" rspace="2px">×</mo>
                    <mfenced open="⌈" close="⌉">
                      <mfrac>
                        <mi>width</mi>
                        <msub>
                          <mi>b</mi>
                          <mi>w</mi>
                        </msub>
                      </mfrac>
                    </mfenced>
                  </mrow>
                </math>
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
          <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>internalformat</code></em> is not
          a supported specific compressed internal formats, or is one of the generic
          compressed internal formats:
          <code class="constant">GL_COMPRESSED_RED</code>,
          <code class="constant">GL_COMPRESSED_RG</code>,
          <code class="constant">GL_COMPRESSED_RGB</code>,
          <code class="constant">GL_COMPRESSED_RGBA</code>.
          <code class="constant">GL_COMPRESSED_SRGB</code>, or
          <code class="constant">GL_COMPRESSED_SRGB_ALPHA</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>imageSize</code></em> is not consistent with
            the format, dimensions, and contents of the specified compressed image data.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>border</code></em> is not 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if parameter combinations are not
            supported by the specific compressed internal format as specified in the
            specific texture compression extension.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be unpacked from the buffer
            object such that the memory reads required would exceed the data store size.
        </p>
        <p>
            Undefined results, including abnormal program termination, are generated if
            <em class="parameter"><code>data</code></em> is not encoded in a manner consistent with the extension
            specification defining the internal compression format.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetCompressedTexImage"><span class="citerefentry"><span class="refentrytitle">glGetCompressedTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_TEXTURE_COMPRESSED</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_NUM_COMPRESSED_TEXTURE_FORMATS</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_COMPRESSED_TEXTURE_FORMATS</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
        </p>
        <p>
            <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with arguments <code class="constant">GL_TEXTURE_INTERNAL_FORMAT</code>
            and <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code>
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
                  <code class="function">glCompressedTexImage1D</code>
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
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage3D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2011-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCompressedTexImage1D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glCompressedTexImage1D glad_glCompressedTexImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCompressedTexSubImage3D'>OpenGL 4</a><br /><a  href='../gl3/glCompressedTexSubImage3D'>OpenGL 3</a><br /><a  href='../gl2/glCompressedTexSubImage3D'>OpenGL 2</a><br /><a  href='../es3/glCompressedTexSubImage3D'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glCompressedTexSubImage3D</h1>
    <div class="refentry" id="glCompressedTexSubImage3D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCompressedTexSubImage3D, glCompressedTextureSubImage3D — specify a three-dimensional texture subimage in a compressed format</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTexSubImage3D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">zoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">depth</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTextureSubImage3D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">zoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">depth</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const void *<var class="pdparam">data</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the target to which the texture is bound for
          <code class="function">glCompressedTexSubImage3D</code> function. Must be
          <code class="constant">GL_TEXTURE_2D_ARRAY</code>,
          <code class="constant">GL_TEXTURE_3D</code>, or
          <code class="constant">GL_TEXTURE_CUBE_MAP_ARRAY</code>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the texture object name for
          <code class="function">glCompressedTextureSubImage3D</code> function.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the level-of-detail number. Level 0 is the base
          image level. Level <span class="emphasis"><em>n</em></span> is the
          <span class="emphasis"><em>n</em></span>th mipmap reduction image.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the x direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>yoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the y direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the width of the texture subimage.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the height of the texture subimage.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>depth</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the depth of the texture subimage.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>format</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the format of the compressed image data stored at
          address <em class="parameter"><code>data</code></em>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>imageSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the number of unsigned bytes of image data starting
          at the address specified by <em class="parameter"><code>data</code></em>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>data</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a pointer to the compressed image data in
          memory.</p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>Texturing allows elements of an image array to be read by
    shaders.</p>
        <p><code class="function">glCompressedTexSubImage3D</code> and
    <code class="function">glCompressedTextureSubImage3D</code> redefine a contiguous
    subregion of an existing three-dimensional texture image. The texels
    referenced by <em class="parameter"><code>data</code></em> replace the portion of the
    existing texture array with x indices <em class="parameter"><code>xoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">width</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            and the y indices <em class="parameter"><code>yoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">height</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            and the z indices <em class="parameter"><code>zoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">zoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">depth</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive.  This region may not include
            any texels outside the range of the texture array as it was originally
            specified.  It is not an error to specify a subtexture with width of 0,
            but such a specification has no effect.
        </p>
        <p>
            <em class="parameter"><code>internalformat</code></em> must be a known compressed image format (such as <code class="constant">GL_RGTC</code>)
            or an extension-specified compressed-texture format.
            The <em class="parameter"><code>format</code></em> of the compressed texture
            image is selected by the GL implementation that compressed it (see
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>) and should be queried at the time the texture was
            compressed with <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>.
        </p>
        <p>
            If a non-zero named buffer object is bound to the <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target
            (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is
            specified, <em class="parameter"><code>data</code></em> is treated as a byte offset into the buffer object's data store.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
          <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>internalformat</code></em> is one of the generic compressed internal formats:
          <code class="constant">GL_COMPRESSED_RED</code>,
          <code class="constant">GL_COMPRESSED_RG</code>,
          <code class="constant">GL_COMPRESSED_RGB</code>,
    <code class="constant">GL_COMPRESSED_RGBA</code>.
    <code class="constant">GL_COMPRESSED_SRGB</code>, or
    <code class="constant">GL_COMPRESSED_SRGB_ALPHA</code>.</p>
        <p><code class="constant">GL_INVALID_ENUM</code> is generated by
    <code class="function">glCompressedTexSubImage3D</code> if
    <em class="parameter"><code>target</code></em> is not
    <code class="constant">GL_TEXTURE_2D_ARRAY</code>,
    <code class="constant">GL_TEXTURE_3D</code>, or
    <code class="constant">GL_TEXTURE_CUBE_MAP_ARRAY</code>.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glCompressedTextureSubImage3D</code> if
    <em class="parameter"><code>texture</code></em> is not the name of an existing texture
    object.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>imageSize</code></em> is not consistent with the format,
    dimensions, and contents of the specified compressed image data.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if parameter
    combinations are not supported by the specific compressed internal format
    as specified in the specific texture compression extension.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero
    buffer object name is bound to the
    <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's
    data store is currently mapped.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero
    buffer object name is bound to the
    <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be
    unpacked from the buffer object such that the memory reads required would
    exceed the data store size.</p>
        <p>Undefined results, including abnormal program termination, are
    generated if <em class="parameter"><code>data</code></em> is not encoded in a manner
    consistent with the extension specification defining the internal
    compression format.</p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetCompressedTexImage"><span class="citerefentry"><span class="refentrytitle">glGetCompressedTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_TEXTURE_COMPRESSED</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
        </p>
        <p>
            <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with arguments <code class="constant">GL_TEXTURE_INTERNAL_FORMAT</code>
            and <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code>
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
                  <code class="function">glCompressedTexSubImage3D</code>
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
                  <code class="function">glCompressedTextureSubImage3D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage3D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCompressedTexSubImage3D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glCompressedTexSubImage3D glad_glCompressedTexSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCompressedTexSubImage2D'>OpenGL 4</a><br /><a  href='../gl3/glCompressedTexSubImage2D'>OpenGL 3</a><br /><a  href='../gl2/glCompressedTexSubImage2D'>OpenGL 2</a><br /><a  href='../es3/glCompressedTexSubImage2D'>OpenGL ES 3</a><br /><a  href='../es2/glCompressedTexSubImage2D'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glCompressedTexSubImage2D</h1>
    <div class="refentry" id="glCompressedTexSubImage2D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCompressedTexSubImage2D, glCompressedTextureSubImage2D — specify a two-dimensional texture subimage in a compressed format</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTexSubImage2D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTextureSubImage2D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const void *<var class="pdparam">data</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the target to which the texture is bound for
          <code class="function">glCompressedTexSubImage2D</code> function. Must be
          <code class="constant">GL_TEXTURE_1D_ARRAY</code>,
          <code class="constant">GL_TEXTURE_2D</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>, or
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the texture object name for
          <code class="function">glCompressedTextureSubImage2D</code> function.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the level-of-detail number. Level 0 is the base
          image level. Level <span class="emphasis"><em>n</em></span> is the
          <span class="emphasis"><em>n</em></span>th mipmap reduction image.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the x direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>yoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the y direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the width of the texture subimage.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the height of the texture subimage.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>format</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the format of the compressed image data stored at
          address <em class="parameter"><code>data</code></em>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>imageSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the number of unsigned bytes of image data starting
          at the address specified by <em class="parameter"><code>data</code></em>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>data</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a pointer to the compressed image data in
          memory.</p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>Texturing allows elements of an image array to be read by
    shaders.</p>
        <p><code class="function">glCompressedTexSubImage2D</code> and
    <code class="function">glCompressedTextureSubImage2D</code> redefine a contiguous
    subregion of an existing two-dimensional texture image. The texels
    referenced by <em class="parameter"><code>data</code></em> replace the portion of the
    existing texture array with x indices <em class="parameter"><code>xoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">width</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            and the y indices <em class="parameter"><code>yoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">height</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive.
            This region may not include any texels
    outside the range of the texture array as it was originally specified. It
    is not an error to specify a subtexture with width of 0, but such a
    specification has no effect.</p>
        <p><em class="parameter"><code>internalformat</code></em> must be a known compressed
    image format (such as <code class="constant">GL_RGTC</code>) or an
    extension-specified compressed-texture format. The
    <em class="parameter"><code>format</code></em> of the compressed texture image is selected
    by the GL implementation that compressed it (see <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>) and should be queried at the time the texture was
    compressed with <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>.</p>
        <p>If a non-zero named buffer object is bound to the
    <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is specified,
    <em class="parameter"><code>data</code></em> is treated as a byte offset into the buffer
    object's data store.</p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p><code class="constant">GL_INVALID_ENUM</code> is generated if
    <em class="parameter"><code>internalformat</code></em> is of the generic compressed
    internal formats: <code class="constant">GL_COMPRESSED_RED</code>,
    <code class="constant">GL_COMPRESSED_RG</code>,
    <code class="constant">GL_COMPRESSED_RGB</code>,
    <code class="constant">GL_COMPRESSED_RGBA</code>.
    <code class="constant">GL_COMPRESSED_SRGB</code>, or
    <code class="constant">GL_COMPRESSED_SRGB_ALPHA</code>.</p>
        <p><code class="constant">GL_INVALID_ENUM</code> is generated by
    <code class="function">glCompressedTexSubImage2D</code> if
    <em class="parameter"><code>target</code></em> is <code class="constant">GL_TEXTURE_RECTANGLE</code>
    or <code class="constant">GL_PROXY_TEXTURE_RECTANGLE</code>.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>imageSize</code></em> is not consistent with the format,
    dimensions, and contents of the specified compressed image data.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if parameter
    combinations are not supported by the specific compressed internal format
    as specified in the specific texture compression extension.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero
    buffer object name is bound to the
    <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's
    data store is currently mapped.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero
    buffer object name is bound to the
    <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be
    unpacked from the buffer object such that the memory reads required would
    exceed the data store size.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glCompressedTextureSubImage2D</code> if
    <em class="parameter"><code>texture</code></em> is not the name of an existing texture
    object.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glCompressedTextureSubImage2D</code> if the effective target
    is <code class="constant">GL_TEXTURE_RECTANGLE</code>.</p>
        <p>Undefined results, including abnormal program termination, are
    generated if <em class="parameter"><code>data</code></em> is not encoded in a manner
    consistent with the extension specification defining the internal
    compression format.</p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetCompressedTexImage"><span class="citerefentry"><span class="refentrytitle">glGetCompressedTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_TEXTURE_COMPRESSED</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
        </p>
        <p>
            <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with arguments <code class="constant">GL_TEXTURE_INTERNAL_FORMAT</code>
            and <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code>
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
                  <code class="function">glCompressedTexSubImage2D</code>
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
                  <code class="function">glCompressedTextureSubImage2D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage3D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCompressedTexSubImage2D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glCompressedTexSubImage2D glad_glCompressedTexSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCompressedTexSubImage1D'>OpenGL 4</a><br /><a  href='../gl3/glCompressedTexSubImage1D'>OpenGL 3</a><br /><a  href='../gl2/glCompressedTexSubImage1D'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glCompressedTexSubImage1D</h1>
    <div class="refentry" id="glCompressedTexSubImage1D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCompressedTexSubImage1D, glCompressedTextureSubImage1D — specify a one-dimensional texture subimage in a compressed
    format</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTexSubImage1D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCompressedTextureSubImage1D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">imageSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const void *<var class="pdparam">data</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the target, to which the texture is bound, for
          <code class="function">glCompressedTexSubImage1D</code> function. Must be
          <code class="constant">GL_TEXTURE_1D</code>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the texture object name for
          <code class="function">glCompressedTextureSubImage1D</code> function.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the level-of-detail number. Level 0 is the base
          image level. Level <span class="emphasis"><em>n</em></span> is the
          <span class="emphasis"><em>n</em></span>th mipmap reduction image.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the x direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the width of the texture subimage.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>format</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the format of the compressed image data stored at
          address <em class="parameter"><code>data</code></em>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>imageSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the number of unsigned bytes of image data starting
          at the address specified by <em class="parameter"><code>data</code></em>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>data</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a pointer to the compressed image data in
          memory.</p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>Texturing allows elements of an image array to be read by
    shaders.</p>
        <p><code class="function">glCompressedTexSubImage1D</code> and
    <code class="function">glCompressedTextureSubImage1D</code> redefine a contiguous
    subregion of an existing one-dimensional texture image. The texels
    referenced by <em class="parameter"><code>data</code></em> replace the portion of the
    existing texture array with x indices <em class="parameter"><code>xoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">width</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive.  This region may not include any texels
    outside the range of the texture array as it was originally specified. It
    is not an error to specify a subtexture with width of 0, but such a
    specification has no effect.</p>
        <p><em class="parameter"><code>internalformat</code></em> must be a known compressed
    image format (such as <code class="constant">GL_RGTC</code>) or an
    extension-specified compressed-texture format. The
    <em class="parameter"><code>format</code></em> of the compressed texture image is selected
    by the GL implementation that compressed it (see <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>), and should be queried at the time the texture was
    compressed with <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>.</p>
        <p>If a non-zero named buffer object is bound to the
    <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is specified,
    <em class="parameter"><code>data</code></em> is treated as a byte offset into the buffer
    object's data store.</p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p><code class="constant">GL_INVALID_ENUM</code> is generated if
    <em class="parameter"><code>internalformat</code></em> is not one of the generic compressed
    internal formats: <code class="constant">GL_COMPRESSED_RED</code>,
    <code class="constant">GL_COMPRESSED_RG</code>,
    <code class="constant">GL_COMPRESSED_RGB</code>,
    <code class="constant">GL_COMPRESSED_RGBA</code>.
    <code class="constant">GL_COMPRESSED_SRGB</code>, or
    <code class="constant">GL_COMPRESSED_SRGB_ALPHA</code>.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>imageSize</code></em> is not consistent with the format,
    dimensions, and contents of the specified compressed image data.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if parameter
    combinations are not supported by the specific compressed internal format
    as specified in the specific texture compression extension.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero
    buffer object name is bound to the
    <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's
    data store is currently mapped.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero
    buffer object name is bound to the
    <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be
    unpacked from the buffer object such that the memory reads required would
    exceed the data store size.</p>
        <p>GL_INVALID_OPERATION is generated by
    <code class="function">glCompressedTextureSubImage1D</code> function if texture is
    not the name of an existing texture object.</p>
        <p>Undefined results, including abnormal program termination, are
    generated if <em class="parameter"><code>data</code></em> is not encoded in a manner
    consistent with the extension specification defining the internal
    compression format.</p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
          <a class="citerefentry" href="glGetCompressedTexImage">
            <span class="citerefentry">
              <span class="refentrytitle">glGetCompressedTexImage</span>
            </span>
          </a>
        </p>
        <p><a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument
    <code class="constant">GL_TEXTURE_COMPRESSED</code></p>
        <p><a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument
    <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code></p>
        <p><a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with arguments
    <code class="constant">GL_TEXTURE_INTERNAL_FORMAT</code> and
    <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code></p>
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
                  <code class="function">glCompressedTexSubImage1D</code>
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
                  <code class="function">glCompressedTextureSubImage1D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage3D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCompressedTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCompressedTexSubImage1D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glCompressedTexSubImage1D glad_glCompressedTexSubImage1D
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void *img);
GLAPI PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetCompressedTexImage'>OpenGL 4</a><br /><a  href='../gl3/glGetCompressedTexImage'>OpenGL 3</a><br /><a  href='../gl2/glGetCompressedTexImage'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glGetCompressedTexImage</h1>
    <div class="refentry" id="glGetCompressedTexImage">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetCompressedTexImage — return a compressed texture image</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetCompressedTexImage</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLvoid * <var class="pdparam">pixels</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetnCompressedTexImage</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">bufSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>void *<var class="pdparam">pixels</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetCompressedTextureImage</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">bufSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>void *<var class="pdparam">pixels</var><code>)</code>;</td>
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
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the target to which the texture is bound for
          <code class="function">glGetCompressedTexImage</code> and
          <code class="function">glGetnCompressedTexImage</code> functions.
          <code class="constant">GL_TEXTURE_1D</code>,
          <code class="constant">GL_TEXTURE_1D_ARRAY</code>,
          <code class="constant">GL_TEXTURE_2D</code>,
          <code class="constant">GL_TEXTURE_2D_ARRAY</code>,
          <code class="constant">GL_TEXTURE_3D</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_ARRAY</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>, and
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>,
          <code class="constant">GL_TEXTURE_RECTANGLE</code> are accepted.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the texture object name for
          <code class="function">glGetCompressedTextureImage</code> function.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the level-of-detail number of the desired image.
          Level 0 is the base image level. Level $n$ is the $n$-th mipmap reduction image.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>bufSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the size of the buffer <em class="parameter"><code>pixels</code></em>
          for <code class="function">glGetCompressedTextureImage</code> and
          <code class="function">glGetnCompressedTexImage</code> functions.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pixels</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Returns the compressed texture image.</p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p><code class="function">glGetCompressedTexImage</code> and
    <code class="function">glGetnCompressedTexImage</code> return the compressed
    texture image associated with <em class="parameter"><code>target</code></em> and
    <em class="parameter"><code>lod</code></em> into <em class="parameter"><code>pixels</code></em>.
    <code class="function">glGetCompressedTextureImage</code> serves the same purpose,
    but instead of taking a texture target, it takes the ID of the texture
    object. <em class="parameter"><code>pixels</code></em> should be an array of
    <em class="parameter"><code>bufSize</code></em> bytes for
    <code class="function">glGetnCompresedTexImage</code> and
    <code class="function">glGetCompressedTextureImage</code> functions, and of
    <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code> bytes in case of
    <code class="function">glGetCompressedTexImage</code>. If the actual data takes
    less space than <em class="parameter"><code>bufSize</code></em>, the remaining bytes will
    not be touched. <em class="parameter"><code>target</code></em> specifies the texture
    target, to which the texture the data the function should extract the data
    from is bound to. <em class="parameter"><code>lod</code></em> specifies the level-of-detail
    number of the desired image.</p>
        <p>If a non-zero named buffer object is bound to the
    <code class="constant">GL_PIXEL_PACK_BUFFER</code> target (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is requested,
    <em class="parameter"><code>pixels</code></em> is treated as a byte offset into the buffer
    object's data store.</p>
        <p>To minimize errors, first verify that the texture is compressed by
    calling <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with argument
    <code class="constant">GL_TEXTURE_COMPRESSED</code>. If the texture is compressed,
    you can determine the amount of memory required to store the compressed
    texture by calling <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with argument
    <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code>. Finally, retrieve
    the internal format of the texture by calling <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with argument
    <code class="constant">GL_TEXTURE_INTERNAL_FORMAT</code>. To store the texture for
    later use, associate the internal format and size with the retrieved
    texture image. These data can be used by the respective texture or
    subtexture loading routine used for loading <em class="parameter"><code>target</code></em>
    textures.</p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glGetCompressedTextureImage</code> if
    <em class="parameter"><code>texture</code></em> is not the name of an existing texture
    object.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>level</code></em> is less than zero or greater than the maximum
    number of LODs permitted by the implementation.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if
    <code class="function">glGetCompressedTexImage</code>,
    <code class="function">glGetnCompressedTexImage</code>, and
    <code class="function">glGetCompressedTextureImage</code> is used to retrieve a
    texture that is in an uncompressed internal format.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero
    buffer object name is bound to the
    <code class="constant">GL_PIXEL_PACK_BUFFER</code> target, the buffer storage was
    not initialized with <code class="function">glBufferStorage</code> using
    <code class="constant">GL_MAP_PERSISTENT_BIT</code> flag, and the buffer object's
    data store is currently mapped.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero
    buffer object name is bound to the
    <code class="constant">GL_PIXEL_PACK_BUFFER</code> target and the data would be
    packed to the buffer object such that the memory writes required would
    exceed the data store size.</p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p><a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with argument
    <code class="constant">GL_TEXTURE_COMPRESSED</code></p>
        <p><a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with argument
    <code class="constant">GL_TEXTURE_COMPRESSED_IMAGE_SIZE</code></p>
        <p><a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a> with argument
    <code class="constant">GL_TEXTURE_INTERNAL_FORMAT</code></p>
        <p><a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument
    <code class="constant">GL_PIXEL_PACK_BUFFER_BINDING</code></p>
      </div>
      <div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://www.oldunreal.com/editing/s3tc/ARB_texture_compression.pdf">S&eacute;bastien Domin&eacute; - Using Texture Compression in OpenGL</a><br /></p></div>
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
                  <code class="function">glGetCompressedTexImage</code>
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
                  <code class="function">glGetCompressedTextureImage</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glGetnCompressedTexImage</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p><a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>, <a class="citerefentry" href="glCompressedTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage1D</span></span></a>, <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>, <a class="citerefentry" href="glCompressedTexImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage3D</span></span></a>, <a class="citerefentry" href="glCompressedTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage1D</span></span></a>, <a class="citerefentry" href="glCompressedTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage2D</span></span></a>, <a class="citerefentry" href="glCompressedTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexSubImage3D</span></span></a>, <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a>, <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>, <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>, <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>, <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>, <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>, <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>, <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a></p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>Copyright © 1991-2006 Silicon Graphics,
    Inc. Copyright © 2010-2014 Khronos Group.
    This document is licensed under the SGI Free Software B License. For
    details, see
    <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
    </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetCompressedTexImage.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetCompressedTexImage glad_glGetCompressedTexImage
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
GLAPI PFNGLCLIENTACTIVETEXTUREPROC glad_glClientActiveTexture;
#define glClientActiveTexture glad_glClientActiveTexture
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DPROC)(GLenum target, GLdouble s);
GLAPI PFNGLMULTITEXCOORD1DPROC glad_glMultiTexCoord1d;
#define glMultiTexCoord1d glad_glMultiTexCoord1d
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVPROC)(GLenum target, const GLdouble *v);
GLAPI PFNGLMULTITEXCOORD1DVPROC glad_glMultiTexCoord1dv;
#define glMultiTexCoord1dv glad_glMultiTexCoord1dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FPROC)(GLenum target, GLfloat s);
GLAPI PFNGLMULTITEXCOORD1FPROC glad_glMultiTexCoord1f;
#define glMultiTexCoord1f glad_glMultiTexCoord1f
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVPROC)(GLenum target, const GLfloat *v);
GLAPI PFNGLMULTITEXCOORD1FVPROC glad_glMultiTexCoord1fv;
#define glMultiTexCoord1fv glad_glMultiTexCoord1fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IPROC)(GLenum target, GLint s);
GLAPI PFNGLMULTITEXCOORD1IPROC glad_glMultiTexCoord1i;
#define glMultiTexCoord1i glad_glMultiTexCoord1i
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVPROC)(GLenum target, const GLint *v);
GLAPI PFNGLMULTITEXCOORD1IVPROC glad_glMultiTexCoord1iv;
#define glMultiTexCoord1iv glad_glMultiTexCoord1iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SPROC)(GLenum target, GLshort s);
GLAPI PFNGLMULTITEXCOORD1SPROC glad_glMultiTexCoord1s;
#define glMultiTexCoord1s glad_glMultiTexCoord1s
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVPROC)(GLenum target, const GLshort *v);
GLAPI PFNGLMULTITEXCOORD1SVPROC glad_glMultiTexCoord1sv;
#define glMultiTexCoord1sv glad_glMultiTexCoord1sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DPROC)(GLenum target, GLdouble s, GLdouble t);
GLAPI PFNGLMULTITEXCOORD2DPROC glad_glMultiTexCoord2d;
#define glMultiTexCoord2d glad_glMultiTexCoord2d
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVPROC)(GLenum target, const GLdouble *v);
GLAPI PFNGLMULTITEXCOORD2DVPROC glad_glMultiTexCoord2dv;
#define glMultiTexCoord2dv glad_glMultiTexCoord2dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FPROC)(GLenum target, GLfloat s, GLfloat t);
GLAPI PFNGLMULTITEXCOORD2FPROC glad_glMultiTexCoord2f;
#define glMultiTexCoord2f glad_glMultiTexCoord2f
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVPROC)(GLenum target, const GLfloat *v);
GLAPI PFNGLMULTITEXCOORD2FVPROC glad_glMultiTexCoord2fv;
#define glMultiTexCoord2fv glad_glMultiTexCoord2fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IPROC)(GLenum target, GLint s, GLint t);
GLAPI PFNGLMULTITEXCOORD2IPROC glad_glMultiTexCoord2i;
#define glMultiTexCoord2i glad_glMultiTexCoord2i
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVPROC)(GLenum target, const GLint *v);
GLAPI PFNGLMULTITEXCOORD2IVPROC glad_glMultiTexCoord2iv;
#define glMultiTexCoord2iv glad_glMultiTexCoord2iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SPROC)(GLenum target, GLshort s, GLshort t);
GLAPI PFNGLMULTITEXCOORD2SPROC glad_glMultiTexCoord2s;
#define glMultiTexCoord2s glad_glMultiTexCoord2s
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVPROC)(GLenum target, const GLshort *v);
GLAPI PFNGLMULTITEXCOORD2SVPROC glad_glMultiTexCoord2sv;
#define glMultiTexCoord2sv glad_glMultiTexCoord2sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLAPI PFNGLMULTITEXCOORD3DPROC glad_glMultiTexCoord3d;
#define glMultiTexCoord3d glad_glMultiTexCoord3d
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVPROC)(GLenum target, const GLdouble *v);
GLAPI PFNGLMULTITEXCOORD3DVPROC glad_glMultiTexCoord3dv;
#define glMultiTexCoord3dv glad_glMultiTexCoord3dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLAPI PFNGLMULTITEXCOORD3FPROC glad_glMultiTexCoord3f;
#define glMultiTexCoord3f glad_glMultiTexCoord3f
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVPROC)(GLenum target, const GLfloat *v);
GLAPI PFNGLMULTITEXCOORD3FVPROC glad_glMultiTexCoord3fv;
#define glMultiTexCoord3fv glad_glMultiTexCoord3fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IPROC)(GLenum target, GLint s, GLint t, GLint r);
GLAPI PFNGLMULTITEXCOORD3IPROC glad_glMultiTexCoord3i;
#define glMultiTexCoord3i glad_glMultiTexCoord3i
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVPROC)(GLenum target, const GLint *v);
GLAPI PFNGLMULTITEXCOORD3IVPROC glad_glMultiTexCoord3iv;
#define glMultiTexCoord3iv glad_glMultiTexCoord3iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
GLAPI PFNGLMULTITEXCOORD3SPROC glad_glMultiTexCoord3s;
#define glMultiTexCoord3s glad_glMultiTexCoord3s
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVPROC)(GLenum target, const GLshort *v);
GLAPI PFNGLMULTITEXCOORD3SVPROC glad_glMultiTexCoord3sv;
#define glMultiTexCoord3sv glad_glMultiTexCoord3sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI PFNGLMULTITEXCOORD4DPROC glad_glMultiTexCoord4d;
#define glMultiTexCoord4d glad_glMultiTexCoord4d
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVPROC)(GLenum target, const GLdouble *v);
GLAPI PFNGLMULTITEXCOORD4DVPROC glad_glMultiTexCoord4dv;
#define glMultiTexCoord4dv glad_glMultiTexCoord4dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI PFNGLMULTITEXCOORD4FPROC glad_glMultiTexCoord4f;
#define glMultiTexCoord4f glad_glMultiTexCoord4f
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVPROC)(GLenum target, const GLfloat *v);
GLAPI PFNGLMULTITEXCOORD4FVPROC glad_glMultiTexCoord4fv;
#define glMultiTexCoord4fv glad_glMultiTexCoord4fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
GLAPI PFNGLMULTITEXCOORD4IPROC glad_glMultiTexCoord4i;
#define glMultiTexCoord4i glad_glMultiTexCoord4i
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVPROC)(GLenum target, const GLint *v);
GLAPI PFNGLMULTITEXCOORD4IVPROC glad_glMultiTexCoord4iv;
#define glMultiTexCoord4iv glad_glMultiTexCoord4iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI PFNGLMULTITEXCOORD4SPROC glad_glMultiTexCoord4s;
#define glMultiTexCoord4s glad_glMultiTexCoord4s
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVPROC)(GLenum target, const GLshort *v);
GLAPI PFNGLMULTITEXCOORD4SVPROC glad_glMultiTexCoord4sv;
#define glMultiTexCoord4sv glad_glMultiTexCoord4sv
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat *m);
GLAPI PFNGLLOADTRANSPOSEMATRIXFPROC glad_glLoadTransposeMatrixf;
#define glLoadTransposeMatrixf glad_glLoadTransposeMatrixf
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble *m);
GLAPI PFNGLLOADTRANSPOSEMATRIXDPROC glad_glLoadTransposeMatrixd;
#define glLoadTransposeMatrixd glad_glLoadTransposeMatrixd
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat *m);
GLAPI PFNGLMULTTRANSPOSEMATRIXFPROC glad_glMultTransposeMatrixf;
#define glMultTransposeMatrixf glad_glMultTransposeMatrixf
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble *m);
GLAPI PFNGLMULTTRANSPOSEMATRIXDPROC glad_glMultTransposeMatrixd;
#define glMultTransposeMatrixd glad_glMultTransposeMatrixd
#endif
#endif