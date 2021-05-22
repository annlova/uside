#ifndef __uside_glad26_h_
#define __uside_glad26_h_
#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
GLAPI int GLAD_GL_VERSION_3_1;
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDrawArraysInstanced'>OpenGL 4</a><br /><a  href='../gl3/glDrawArraysInstanced'>OpenGL 3</a><br /><a  href='../es3/glDrawArraysInstanced'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glDrawArraysInstanced</h1>
    <div class="refentry" id="glDrawArraysInstanced">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDrawArraysInstanced — draw multiple instances of a range of elements</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDrawArraysInstanced</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">first</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">count</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">primcount</var><code>)</code>;</td>
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
                    Specifies what kind of primitives to render. Symbolic constants <code class="constant">GL_POINTS</code>,
                    <code class="constant">GL_LINE_STRIP</code>, <code class="constant">GL_LINE_LOOP</code>, <code class="constant">GL_LINES</code>,
                    <code class="constant">GL_TRIANGLE_STRIP</code>, <code class="constant">GL_TRIANGLE_FAN</code>, <code class="constant">GL_TRIANGLES</code>
                    <code class="constant">GL_LINES_ADJACENCY</code>, <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code>, <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code> and <code class="constant">GL_PATCHES</code>
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
                    Specifies the starting index in the enabled arrays.
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
                    Specifies the number of indices to be rendered.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>primcount</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of instances of the specified range of indices to be rendered.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDrawArraysInstanced</code> behaves identically to <a class="citerefentry" href="glDrawArrays"><span class="citerefentry"><span class="refentrytitle">glDrawArrays</span></span></a>
            except that <em class="parameter"><code>primcount</code></em> instances of the range of elements are executed and the value of the internal counter
            <em class="parameter"><code>instanceID</code></em> advances for each iteration. <em class="parameter"><code>instanceID</code></em> is an internal 32-bit integer counter
            that may be read by a vertex shader as <code class="constant">gl_InstanceID</code>.
        </p>
        <p>
            <code class="function">glDrawArraysInstanced</code> has the same effect as:
            </p>
        <pre class="programlisting">    if ( mode or count is invalid )
        generate appropriate error
    else {
        for (int i = 0; i &lt; primcount ; i++) {
            instanceID = i;
            glDrawArrays(mode, first, count);
        }
        instanceID = 0;
    }</pre>
        <p>
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not one of
            the accepted values.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a geometry shader is active and <em class="parameter"><code>mode</code></em>
            is incompatible with the input primitive type of the geometry shader in the currently installed program object.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>count</code></em> or <em class="parameter"><code>primcount</code></em> are negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to an
            enabled array and the buffer object's data store is currently mapped.
        </p>
      </div>
      <div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://www.opengl-tutorial.org/intermediate-tutorials/billboards-particles/particles-instancing/">opengl-tutorial.org - Particles / Instancing</a><br /></p></div>
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
                  <code class="function">glDrawArraysInstanced</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glDrawElementsInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstanced</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDrawArraysInstanced.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glDrawArraysInstanced glad_glDrawArraysInstanced
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLAPI PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDrawElementsInstanced'>OpenGL 4</a><br /><a  href='../gl3/glDrawElementsInstanced'>OpenGL 3</a><br /><a  href='../es3/glDrawElementsInstanced'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glDrawElementsInstanced</h1>
    <div class="refentry" id="glDrawElementsInstanced">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDrawElementsInstanced — draw multiple instances of a set of elements</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDrawElementsInstanced</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
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
              <td>const void * <var class="pdparam">indices</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">primcount</var><code>)</code>;</td>
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
                    Specifies the type of the values in <em class="parameter"><code>indices</code></em>. Must be one of <code class="constant">GL_UNSIGNED_BYTE</code>,
                    <code class="constant">GL_UNSIGNED_SHORT</code>, or <code class="constant">GL_UNSIGNED_INT</code>.
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
                  <code>primcount</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of instances of the specified range of indices to be rendered.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDrawElementsInstanced</code> behaves identically to <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a>
            except that <em class="parameter"><code>primcount</code></em> instances of the set of elements are executed and the value of the internal counter
            <em class="parameter"><code>instanceID</code></em> advances for each iteration. <em class="parameter"><code>instanceID</code></em> is an internal 32-bit integer counter
            that may be read by a vertex shader as <code class="constant">gl_InstanceID</code>.
        </p>
        <p>
            <code class="function">glDrawElementsInstanced</code> has the same effect as:
            </p>
        <pre class="programlisting">    if (mode, count, or type is invalid )
        generate appropriate error
    else {
        for (int i = 0; i &lt; primcount ; i++) {
            instanceID = i;
            glDrawElements(mode, count, type, indices);
        }
        instanceID = 0;
    }</pre>
        <p>
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glDrawElementsInstanced</code> is available only if the GL version is 3.1 or greater.
        </p>
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
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not one of <code class="constant">GL_POINTS</code>,
            <code class="constant">GL_LINE_STRIP</code>, <code class="constant">GL_LINE_LOOP</code>, <code class="constant">GL_LINES</code>,
            <code class="constant">GL_TRIANGLE_STRIP</code>, <code class="constant">GL_TRIANGLE_FAN</code>, or <code class="constant">GL_TRIANGLES</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>count</code></em> or <em class="parameter"><code>primcount</code></em> are negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a geometry shader is active and <em class="parameter"><code>mode</code></em>
            is incompatible with the input primitive type of the geometry shader in the currently installed program object.
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
                  <code class="function">glDrawElementsInstanced</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glDrawArraysInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawArraysInstanced</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDrawElementsInstanced.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glDrawElementsInstanced glad_glDrawElementsInstanced
typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
GLAPI PFNGLTEXBUFFERPROC glad_glTexBuffer;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glTexBuffer'>OpenGL 4</a><br /><a  href='../gl3/glTexBuffer'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glTexBuffer</h1>
    <div class="refentry" id="glTexBuffer">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glTexBuffer, glTextureBuffer — attach a buffer object's data store to a buffer texture object</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTexBuffer</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">internalFormat</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">buffer</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTextureBuffer</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">internalformat</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">buffer</var><code>)</code>;</td>
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
                    Specifies the target to which the texture is bound for
                    <code class="function">glTexBuffer</code>. Must be
                    <code class="constant">GL_TEXTURE_BUFFER</code>.
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
                    <code class="function">glTextureBuffer</code>.
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
                    Specifies the internal format of the data in the store
                    belonging to <em class="parameter"><code>buffer</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>buffer</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of the buffer object whose storage to
                    attach to the active buffer texture.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glTexBuffer</code> and
            <code class="function">glTextureBuffer</code> attaches the data store of
            a specified buffer object to a specified texture object, and
            specify the storage format for the texture image found found in
            the buffer object. The texture object must be a buffer texture.
        </p>
        <p>
            If <em class="parameter"><code>buffer</code></em> is zero, any buffer object
            attached to the buffer texture is detached and no new buffer
            object is attached. If <em class="parameter"><code>buffer</code></em> is
            non-zero, it must be the name of an existing buffer object.
        </p>
        <p>
            <em class="parameter"><code>internalformat</code></em> specifies the storage
            format, and must be one of the following sized internal formats:
        </p>
        <p>
            <em class="parameter"><code>internalformat</code></em> specifies the storage
            format, and must be one of the following sized internal formats:
        </p>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; " class="col1"/>
              <col style="text-align: left; " class="col2"/>
              <col style="text-align: left; " class="col3"/>
              <col style="text-align: left; " class="col4"/>
              <col style="text-align: center; " class="col5"/>
              <col style="text-align: center; " class="col6"/>
              <col style="text-align: center; " class="col7"/>
              <col style="text-align: center; " class="col8"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; "> </th>
                <th style="text-align: left; border-right: 2px solid ; "> </th>
                <th style="text-align: left; border-right: 2px solid ; "> </th>
                <th style="text-align: left; border-right: 2px solid ; "> </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="4">
                    <span class="bold"><strong> Component </strong></span>
                </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <span class="bold">
                    <strong>Sized Internal Format</strong>
                  </span>
                </th>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <span class="bold">
                    <strong>Base Type</strong>
                  </span>
                </th>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <span class="bold">
                    <strong>Components</strong>
                  </span>
                </th>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <span class="bold">
                    <strong>Norm</strong>
                  </span>
                </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">1</th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">2</th>
                <th style="text-align: center; border-bottom: 2px solid ; ">3</th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R8</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ubyte</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">YES</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R16</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ushort</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">YES</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R16F</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">half</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R32F</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">float</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R8I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">byte</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R16I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">short</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R32I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">int</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R8UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ubyte</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R16UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ushort</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_R32UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">uint</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">1</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG8</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ubyte</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">YES</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG16</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ushort</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">YES</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG16F</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">half</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG32F</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">float</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG8I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">byte</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG16I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">short</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG32I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">int</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG8UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ubyte</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG16UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ushort</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RG32UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">uint</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">2</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">0</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGB32F</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">float</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">3</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGB32I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">int</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">3</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGB32UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">uint</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">3</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">1</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA8</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">uint</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">YES</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA16</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">short</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">YES</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA16F</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">half</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA32F</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">float</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA8I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">byte</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA16I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">short</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA32I</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">int</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA8UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ubyte</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_RGBA16UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">ushort</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">B</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">A</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="constant">GL_RGBA32UI</code>
                </td>
                <td style="text-align: left; border-right: 2px solid ; ">uint</td>
                <td style="text-align: left; border-right: 2px solid ; ">4</td>
                <td style="text-align: left; border-right: 2px solid ; ">NO</td>
                <td style="text-align: center; border-right: 2px solid ; ">R</td>
                <td style="text-align: center; border-right: 2px solid ; ">G</td>
                <td style="text-align: center; border-right: 2px solid ; ">B</td>
                <td style="text-align: center; ">A</td>
              </tr>
            </tbody>
          </table>
        </div>
        <p>
            When a buffer object is attached to a buffer texture, the buffer
            object's data store is taken as the texture's texel array. The
            number of texels in the buffer texture's texel array is given by
                $$ \left\lfloor { size \over { components \times sizeof(base\_type) } } \right\rfloor $$
            where $size$ is the size of the buffer object in basic machine
            units (the value of <code class="constant">GL_BUFFER_SIZE</code> for
            <em class="parameter"><code>buffer</code></em>), and $components$ and
            $base\_type$ are the element count and base data type for
            elements, as specified in the table above. The number of texels
            in the texel array is then clamped to the value of the
            implementation-dependent limit
            <code class="constant">GL_MAX_TEXTURE_BUFFER_SIZE</code>. When a buffer
            texture is accessed in a shader, the results of a texel fetch
            are undefined if the specified texel coordinate is negative, or
            greater than or equal to the clamped number of texels in the
            texel array.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated by
            <code class="function">glTexBuffer</code> if
            <em class="parameter"><code>target</code></em> is not
            <code class="constant">GL_TEXTURE_BUFFER</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glTextureBuffer</code> if
            <em class="parameter"><code>texture</code></em> is not the name of an existing
            texture object.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated by
            <code class="function">glTextureBuffer</code> if the effective target of
            <em class="parameter"><code>texture</code></em> is not
            <code class="constant">GL_TEXTURE_BUFFER</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if
            <em class="parameter"><code>internalformat</code></em> is not one of the sized
            internal formats described above.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if
            <em class="parameter"><code>buffer</code></em> is not zero and is not the name of
            an existing buffer object.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>
            with argument <code class="constant">GL_MAX_TEXTURE_BUFFER_SIZE</code>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>
            with argument <code class="constant">GL_TEXTURE_BINDING_BUFFER</code>
        </p>
        <p>
            <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>
            with argument
            <code class="constant">GL_TEXTURE_BUFFER_DATA_STORE_BINDING</code>
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
                  <code class="function">glTexBuffer</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glTextureBuffer</code>
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
            <a class="citerefentry" href="glGenBuffers"><span class="citerefentry"><span class="refentrytitle">glGenBuffers</span></span></a>,
            <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>,
            <a class="citerefentry" href="glBufferData"><span class="citerefentry"><span class="refentrytitle">glBufferData</span></span></a>,
            <a class="citerefentry" href="glDeleteBuffers"><span class="citerefentry"><span class="refentrytitle">glDeleteBuffers</span></span></a>,
            <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a>,
            <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>,
            <a class="citerefentry" href="glDeleteTextures"><span class="citerefentry"><span class="refentrytitle">glDeleteTextures</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glTexBuffer.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glTexBuffer glad_glTexBuffer
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
GLAPI PFNGLPRIMITIVERESTARTINDEXPROC glad_glPrimitiveRestartIndex;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glPrimitiveRestartIndex'>OpenGL 4</a><br /><a  href='../gl3/glPrimitiveRestartIndex'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glPrimitiveRestartIndex</h1>
    <div class="refentry" id="glPrimitiveRestartIndex">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glPrimitiveRestartIndex — specify the primitive restart index</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPrimitiveRestartIndex</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">index</var><code>)</code>;</td>
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
                  <code>index</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the value to be interpreted as the primitive restart index.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glPrimitiveRestartIndex</code> specifies a vertex array element that is treated specially when
            primitive restarting is enabled. This is known as the primitive restart index.
        </p>
        <p>
            When one of the <code class="function">Draw*</code> commands transfers a set of generic attribute array elements to
            the GL, if the index within the vertex arrays corresponding to that set is equal to the primitive restart
            index, then the GL does not process those elements as a vertex. Instead, it is as if the drawing command
            ended with the immediately preceding transfer, and another drawing command is immediately started with
            the same parameters, but only transferring the immediately following element through the end of the
            originally specified elements.
        </p>
        <p>
            When either <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstancedBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstancedBaseVertex</span></span></a> or
            <a class="citerefentry" href="glMultiDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glMultiDrawElementsBaseVertex</span></span></a> is used, the primitive restart
            comparison occurs before the basevertex offset is added to the array index.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glPrimitiveRestartIndex</code> is available only if the GL version is 3.1 or greater.
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
                  <code class="function">glPrimitiveRestartIndex</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstancedBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstancedBaseVertex</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glPrimitiveRestartIndex.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glPrimitiveRestartIndex glad_glPrimitiveRestartIndex
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCopyBufferSubData'>OpenGL 4</a><br /><a  href='../gl3/glCopyBufferSubData'>OpenGL 3</a><br /><a  href='../es3/glCopyBufferSubData'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glCopyBufferSubData</h1>
    <div class="refentry" id="glCopyBufferSubData">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCopyBufferSubData, glCopyNamedBufferSubData — copy all or part of the data store of a buffer object to the data store of another buffer object</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyBufferSubData</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">readTarget</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">writeTarget</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLintptr <var class="pdparam">readOffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLintptr <var class="pdparam">writeOffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizeiptr <var class="pdparam">size</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyNamedBufferSubData</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">readBuffer</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">writeBuffer</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLintptr <var class="pdparam">readOffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLintptr <var class="pdparam">writeOffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">size</var><code>)</code>;</td>
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
                  <code>readTarget</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target to which the source buffer object
                    is bound for <code class="function">glCopyBufferSubData</code>
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>writeTarget</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target to which the destination buffer
                    object is bound for
                    <code class="function">glCopyBufferSubData</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>readBuffer</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of the source buffer object for
                    <code class="function">glCopyNamedBufferSubData</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>writeBuffer</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of the destination buffer object for
                    <code class="function">glCopyNamedBufferSubData</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>readOffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the offset, in basic machine units, within the
                    data store of the source buffer object at which data
                    will be read.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>writeOffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the offset, in basic machine units, within the
                    data store of the destination buffer object at which
                    data will be written.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>size</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the size, in basic machine units, of the data
                    to be copied from the source buffer object to the
                    destination buffer object.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glCopyBufferSubData</code> and
            <code class="function">glCopyNamedBufferSubData</code> copy part of the
            data store attached to a source buffer object to the data store
            attached to a destination buffer object. The number of basic
            machine units indicated by <em class="parameter"><code>size</code></em> is copied
            from the source at offset <em class="parameter"><code>readOffset</code></em> to
            the destination at <em class="parameter"><code>writeOffset</code></em>.
            <em class="parameter"><code>readOffset</code></em>,
            <em class="parameter"><code>writeOffset</code></em> and
            <em class="parameter"><code>size</code></em> are in terms of basic machine units.
        </p>
        <p>
            For <code class="function">glCopyBufferSubData</code>,
            <em class="parameter"><code>readTarget</code></em> and
            <em class="parameter"><code>writeTarget</code></em> specify the targets to which
            the source and destination buffer objects are bound, and must
            each be one of the buffer binding targets in the following
            table:
        </p>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; " class="col1"/>
              <col style="text-align: left; " class="col2"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <span class="bold">
                    <strong>Buffer Binding Target</strong>
                  </span>
                </th>
                <th style="text-align: left; border-bottom: 2px solid ; ">
                  <span class="bold">
                    <strong>Purpose</strong>
                  </span>
                </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_ARRAY_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Vertex attributes</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_ATOMIC_COUNTER_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Atomic counter storage</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_COPY_READ_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Buffer copy source</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_COPY_WRITE_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Buffer copy destination</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_DISPATCH_INDIRECT_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Indirect compute dispatch commands</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_DRAW_INDIRECT_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Indirect command arguments</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_ELEMENT_ARRAY_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Vertex array indices</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_PIXEL_PACK_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Pixel read target</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_PIXEL_UNPACK_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Texture data source</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_QUERY_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Query result buffer</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_SHADER_STORAGE_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Read-write storage for shaders</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_TEXTURE_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Texture data buffer</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER</code>
                </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">Transform feedback buffer</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="constant">GL_UNIFORM_BUFFER</code>
                </td>
                <td style="text-align: left; ">Uniform block storage</td>
              </tr>
            </tbody>
          </table>
        </div>
        <p>
            Any of these targets may be used, but the targets
            <code class="constant">GL_COPY_READ_BUFFER</code> and
            <code class="constant">GL_COPY_WRITE_BUFFER</code> are provided
            specifically to allow copies between buffers without disturbing
            other GL state.
        </p>
        <p>
            <em class="parameter"><code>readOffset</code></em>,
            <em class="parameter"><code>writeOffset</code></em> and
            <em class="parameter"><code>size</code></em> must all be greater than or equal to
            zero. Furthermore, $readOffset+size$ must not exceeed the size
            of the source buffer object, and $writeOffset+size$ must not
            exceeed the size of the buffer bound to
            <em class="parameter"><code>writeTarget</code></em>. If the source and
            destination are the same buffer object, then the source and
            destination ranges must not overlap.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The <code class="constant">GL_DISPATCH_INDIRECT_BUFFER</code> and
            <code class="constant">GL_SHADER_STORAGE_BUFFER</code> targets are
            available only if the GL version is 4.3 or greater.
        </p>
        <p>
            The <code class="constant">GL_QUERY_BUFFER</code> target is available
            only if the GL version is 4.4 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated by
            <code class="function">glCopyBufferSubData</code> if
            <em class="parameter"><code>readTarget</code></em> or
            <em class="parameter"><code>writeTarget</code></em> is not one of the buffer
            binding targets listed above.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glCopyBufferSubData</code> if zero is bound to
            <em class="parameter"><code>readTarget</code></em> or
            <em class="parameter"><code>writeTarget</code></em>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glCopyNamedBufferSubData</code> if
            <em class="parameter"><code>readBuffer</code></em> or
            <em class="parameter"><code>writeBuffer</code></em> is not the name of an
            existing buffer object.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if any of
            <em class="parameter"><code>readOffset</code></em>,
            <em class="parameter"><code>writeOffset</code></em> or
            <em class="parameter"><code>size</code></em> is negative, if $readOffset + size$
            is greater than the size of the source buffer object (its value
            of <code class="constant">GL_BUFFER_SIZE</code>), or if $writeOffset +
            size$ is greater than the size of the destination buffer object.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if the source
            and destination are the same buffer object, and the ranges
            $[readOffset,readOffset+size)$ and
            $[writeOffset,writeOffset+size)$ overlap.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if either
            the source or destination buffer object is mapped with
            <a class="citerefentry" href="glMapBufferRange"><span class="citerefentry"><span class="refentrytitle">glMapBufferRange</span></span></a>
            or
            <a class="citerefentry" href="glMapBuffer"><span class="citerefentry"><span class="refentrytitle">glMapBuffer</span></span></a>,
            unless they were mapped with the
            <code class="constant">GL_MAP_PERSISTENT</code> bit set in the
            <code class="function">glMapBufferRange</code>
            <em class="parameter"><code>access</code></em> flags.
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
                  <code class="function">glCopyBufferSubData</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glCopyNamedBufferSubData</code>
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
            <a class="citerefentry" href="glGenBuffers"><span class="citerefentry"><span class="refentrytitle">glGenBuffers</span></span></a>,
            <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>,
            <a class="citerefentry" href="glBufferData"><span class="citerefentry"><span class="refentrytitle">glBufferData</span></span></a>,
            <a class="citerefentry" href="glBufferSubData"><span class="citerefentry"><span class="refentrytitle">glBufferSubData</span></span></a>,
            <a class="citerefentry" href="glGetBufferSubData"><span class="citerefentry"><span class="refentrytitle">glGetBufferSubData</span></span></a>,
            <a class="citerefentry" href="glMapBuffer"><span class="citerefentry"><span class="refentrytitle">glMapBuffer</span></span></a>,
            <a class="citerefentry" href="glMapBufferRange"><span class="citerefentry"><span class="refentrytitle">glMapBufferRange</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCopyBufferSubData.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glCopyBufferSubData glad_glCopyBufferSubData
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLAPI PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetUniformIndices'>OpenGL 4</a><br /><a  href='../gl3/glGetUniformIndices'>OpenGL 3</a><br /><a  href='../es3/glGetUniformIndices'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glGetUniformIndices</h1>
    <div class="refentry" id="glGetUniformIndices">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetUniformIndices — retrieve the index of a named uniform block</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetUniformIndices</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">program</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">uniformCount</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLchar **<var class="pdparam">uniformNames</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint *<var class="pdparam">uniformIndices</var><code>)</code>;</td>
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
                  <code>program</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of a program containing uniforms whose indices to query.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformCount</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of uniforms whose indices to query.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformNames</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of an array of pointers to buffers containing the names of the queried uniforms.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformIndices</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of an array that will receive the indices of the uniforms.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetUniformIndices</code> retrieves the indices of a number of uniforms within <em class="parameter"><code>program</code></em>.
        </p>
        <p>
            <em class="parameter"><code>program</code></em> must be the name of a program object for which the command
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> must have been called in the past, although it is not required that
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> must have succeeded. The link could have failed because the number
            of active uniforms exceeded the limit.
        </p>
        <p>
            <em class="parameter"><code>uniformCount</code></em> indicates both the number of elements in the array of names <em class="parameter"><code>uniformNames</code></em> and the
            number of indices that may be written to <em class="parameter"><code>uniformIndices</code></em>.
        </p>
        <p>
            <em class="parameter"><code>uniformNames</code></em> contains a list of <em class="parameter"><code>uniformCount</code></em> name strings identifying the uniform names to be
            queried for indices. For each name string in <em class="parameter"><code>uniformNames</code></em>, the index assigned to the active uniform of that name will
            be written to the corresponding element of <em class="parameter"><code>uniformIndices</code></em>. If a string in <em class="parameter"><code>uniformNames</code></em> is not
            the name of an active uniform, the special value <code class="constant">GL_INVALID_INDEX</code> will be written to the corresponding element of
            <em class="parameter"><code>uniformIndices</code></em>.
        </p>
        <p>
            If an error occurs, nothing is written to <em class="parameter"><code>uniformIndices</code></em>.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>program</code></em> is not the name of a program object for which
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> has been called in the past.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glGetUniformIndices</code> is available only if the GL version is 3.1 or greater.
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
                  <code class="function">glGetUniformIndices</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glGetActiveUniform"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniform</span></span></a>,
            <a class="citerefentry" href="glGetActiveUniformName"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniformName</span></span></a>,
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetUniformIndices.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetUniformIndices glad_glGetUniformIndices
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLAPI PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetActiveUniformsiv'>OpenGL 4</a><br /><a  href='../gl3/glGetActiveUniformsiv'>OpenGL 3</a><br /><a  href='../es3/glGetActiveUniformsiv'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glGetActiveUniformsiv</h1>
    <div class="refentry" id="glGetActiveUniformsiv">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetActiveUniformsiv — Returns information about several active uniform variables for the specified program object</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetActiveUniformsiv</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">program</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">uniformCount</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLuint *<var class="pdparam">uniformIndices</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint *<var class="pdparam">params</var><code>)</code>;</td>
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
                  <code>program</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the program object to be queried.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformCount</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies both the number of elements in the array of
            indices <em class="parameter"><code>uniformIndices</code></em> and the number of
            parameters written to <em class="parameter"><code>params</code></em> upon
            successful return.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformIndices</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the address of an array of
            <em class="parameter"><code>uniformCount</code></em> integers containing the
            indices of uniforms within <em class="parameter"><code>program</code></em> whose
            parameter <em class="parameter"><code>pname</code></em> should be queried.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pname</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the property of each uniform in
            <em class="parameter"><code>uniformIndices</code></em> that should be written
            into the corresponding element of
            <em class="parameter"><code>params</code></em>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>params</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the address of an array of
            <em class="parameter"><code>uniformCount</code></em> integers which are to
            receive the value of <em class="parameter"><code>pname</code></em> for each
            uniform in <em class="parameter"><code>uniformIndices</code></em>.</p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetActiveUniformsiv</code> queries the value of
            the parameter named <em class="parameter"><code>pname</code></em> for each of the
            uniforms within <em class="parameter"><code>program</code></em> whose indices are
            specified in the array of <em class="parameter"><code>uniformCount</code></em>
            unsigned integers <em class="parameter"><code>uniformIndices</code></em>. Upon
            success, the value of the parameter for each uniform is written
            into the corresponding entry in the array whose address is given
            in <em class="parameter"><code>params</code></em>. If an error is generated,
            nothing is written into <em class="parameter"><code>params</code></em>.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is
            <code class="constant">GL_UNIFORM_TYPE</code>, then an array identifying
            the types of uniforms specified by the corresponding array of
            <em class="parameter"><code>uniformIndices</code></em> is returned. The returned
            types can be any of the values from the following table:
        </p>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: left; "/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <span class="bold"><strong> Returned Symbolic Contant </strong></span>
                        </th>
                <th style="text-align: left; border-bottom: 2px solid ; ">
                            <span class="bold"><strong> Shader Uniform Type </strong></span>
                        </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">float</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_VEC2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">vec2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_VEC3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">vec3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_VEC4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">vec4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">double</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_VEC2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dvec2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_VEC3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dvec3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_VEC4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dvec4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">int</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_VEC2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">ivec2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_VEC3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">ivec3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_VEC4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">ivec4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">unsigned int</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_VEC2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">uvec2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_VEC3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">uvec3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_VEC4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">uvec4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_BOOL</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">bool</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_BOOL_VEC2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">bvec2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_BOOL_VEC3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">bvec3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_BOOL_VEC4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">bvec4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT2x3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat2x3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT2x4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat2x4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT3x2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat3x2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT3x4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat3x4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT4x2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat4x2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_FLOAT_MAT4x3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">mat4x3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT2x3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat2x3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT2x4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat2x4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT3x2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat3x2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT3x4</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat3x4</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT4x2</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat4x2</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_DOUBLE_MAT4x3</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">dmat4x3</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_1D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler1D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_2D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler2D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_3D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler3D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_CUBE</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">samplerCube</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_1D_SHADOW</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler1DShadow</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_2D_SHADOW</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler2DShadow</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_1D_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler1DArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_2D_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler2DArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_1D_ARRAY_SHADOW</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler1DArrayShadow</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_2D_ARRAY_SHADOW</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler2DArrayShadow</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_2D_MULTISAMPLE</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler2DMS</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_2D_MULTISAMPLE_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler2DMSArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_CUBE_SHADOW</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">samplerCubeShadow</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_BUFFER</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">samplerBuffer</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_2D_RECT</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler2DRect</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_SAMPLER_2D_RECT_SHADOW</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">sampler2DRectShadow</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_1D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isampler1D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_2D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isampler2D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_3D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isampler3D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_CUBE</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isamplerCube</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_1D_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isampler1DArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_2D_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isampler2DArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_2D_MULTISAMPLE</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isampler2DMS</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isampler2DMSArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_BUFFER</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isamplerBuffer</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_INT_SAMPLER_2D_RECT</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">isampler2DRect</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_1D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usampler1D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_2D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usampler2D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_3D</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usampler3D</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_CUBE</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usamplerCube</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_1D_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usampler2DArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_2D_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usampler2DArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usampler2DMS</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usampler2DMSArray</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_BUFFER</code>
                        </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                            <code class="constant">usamplerBuffer</code>
                        </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                            <code class="constant">GL_UNSIGNED_INT_SAMPLER_2D_RECT</code>
                        </td>
                <td style="text-align: left; ">
                            <code class="constant">usampler2DRect</code>
                        </td>
              </tr>
            </tbody>
          </table>
        </div>
        <p>
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_SIZE</code>, then an array identifying the
            size of the uniforms specified by the corresponding array of <em class="parameter"><code>uniformIndices</code></em> is
            returned. The sizes returned are in units of the type returned by a query of <code class="constant">GL_UNIFORM_TYPE</code>.
            For active uniforms that are arrays, the size is the number of active elements in the array;
            for all other uniforms, the size is one.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_NAME_LENGTH</code>, then an array identifying the
            length, including the terminating null character, of the uniform name strings specified by the corresponding
            array of <em class="parameter"><code>uniformIndices</code></em> is returned.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_BLOCK_INDEX</code>, then an array identifying the
            the uniform block index of each of the uniforms specified by the corresponding array of <em class="parameter"><code>uniformIndices</code></em>
            is returned. The uniform block index of a uniform associated with the default uniform block is -1.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_OFFSET</code>, then an array of uniform buffer
            offsets is returned. For uniforms in a named uniform block, the returned value will be its offset, in basic
            machine units, relative to the beginning of the uniform block in the buffer object data store.
            For atomic counter uniforms, the returned value will be its offset relative to the beginning of its active
            atomic counter buffer.
            For all other uniforms, -1 will be returned.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_ARRAY_STRIDE</code>, then an array identifying the
            stride between elements of each of the uniforms specified by the corresponding array of
            <em class="parameter"><code>uniformIndices</code></em> is returned.
            For uniforms in named uniform blocks and for uniforms declared as atomic counters, the stride is the difference,
            in basic machine units, of consecutive elements in an array, or zero for uniforms not declared as an array.
            For all other uniforms, a stride of -1 will be returned.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_MATRIX_STRIDE</code>, then an array identifying the stride
            between columns of a column-major matrix or rows of a row-major matrix, in basic machine units, of each of the uniforms
            specified by the corresponding array of <em class="parameter"><code>uniformIndices</code></em> is returned. The matrix stride of a
            uniform associated with the default uniform block is -1. Note that this information only makes sense for uniforms
            that are matrices. For uniforms that are not matrices, but are declared in a named uniform block, a matrix stride of
            zero is returned.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_IS_ROW_MAJOR</code>, then an array identifying whether each
            of the uniforms specified by the corresponding array of <em class="parameter"><code>uniformIndices</code></em> is a row-major matrix or not is returned. A
            value of one indicates a row-major matrix, and a value of zero indicates a column-major matrix, a matrix in the default
            uniform block, or a non-matrix.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX</code>, then an array
            identifying the active atomic counter buffer index of each of the uniforms specified by the corresponding array
            of <em class="parameter"><code>uniformIndices</code></em> is returned. For uniforms other than atomic counters, the returned buffer
            index is -1. The returned indices may be passed to <a class="citerefentry" href="glGetActiveAtomicCounterBufferiv"><span class="citerefentry"><span class="refentrytitle">glGetActiveAtomicCounterBufferiv</span></span></a>
            to query the properties of the associated buffer, and not necessarily the binding point specified in the uniform declaration.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The double types, <code class="constant">GL_DOUBLE</code>, <code class="constant">GL_DOUBLE_VEC2</code>,
            <code class="constant">GL_DOUBLE_VEC3</code>, <code class="constant">GL_DOUBLE_VEC4</code>,
            <code class="constant">GL_DOUBLE_MAT2</code>, <code class="constant">GL_DOUBLE_MAT3</code>,
            <code class="constant">GL_DOUBLE_MAT4</code>, <code class="constant">GL_DOUBLE_MAT2x3</code>,
            <code class="constant">GL_DOUBLE_MAT2x4</code>, <code class="constant">GL_DOUBLE_MAT3x2</code>,
            <code class="constant">GL_DOUBLE_MAT3x4</code>, <code class="constant">GL_DOUBLE_MAT4x2</code>,
            and <code class="constant">GL_DOUBLE_MAT4x3</code> are only available if the GL
            version is 4.1 or higher.
        </p>
        <p>
            <code class="constant">GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX</code> is only accepted by <em class="parameter"><code>pname</code></em>
            if the GL version is 4.2 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>program</code></em> is not a value generated by
    OpenGL.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if
    <em class="parameter"><code>program</code></em> is not a program object.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>uniformCount</code></em> is greater than or equal to the
    value of <code class="constant">GL_ACTIVE_UNIFORMS</code> for
    <em class="parameter"><code>program</code></em>.</p>
        <p><code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>pname</code></em>
    is not an accepted token.</p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p><a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>
    with argument <code class="constant">GL_MAX_VERTEX_UNIFORM_COMPONENTS</code>,
    <code class="constant">GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS</code>,
    <code class="constant">GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS</code>,
    <code class="constant">GL_MAX_GEOMETRY_UNIFORM_COMPONENTS</code>,
    <code class="constant">GL_MAX_FRAGMENT_UNIFORM_COMPONENTS</code>, or
    <code class="constant">GL_MAX_COMBINED_UNIFORM_COMPONENTS</code>.</p>
        <p><a class="citerefentry" href="glGetProgram"><span class="citerefentry"><span class="refentrytitle">glGetProgram</span></span></a>
    with argument <code class="constant">GL_ACTIVE_UNIFORMS</code> or
    <code class="constant">GL_ACTIVE_UNIFORM_MAX_LENGTH</code>.</p>
        <p>
          <a class="citerefentry" href="glIsProgram">
            <span class="citerefentry">
              <span class="refentrytitle">glIsProgram</span>
            </span>
          </a>
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
                  <code class="function">glGetActiveUniformsiv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
        <p><a class="citerefentry" href="glGetUniform"><span class="citerefentry"><span class="refentrytitle">glGetUniform</span></span></a>,
    <a class="citerefentry" href="glGetActiveUniform"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniform</span></span></a>,
    <a class="citerefentry" href="glGetUniformLocation"><span class="citerefentry"><span class="refentrytitle">glGetUniformLocation</span></span></a>,
    <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a>,
    <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>,
    <a class="citerefentry" href="glUseProgram"><span class="citerefentry"><span class="refentrytitle">glUseProgram</span></span></a></p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2011-2014 Khronos Group
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetActiveUniformsiv.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetActiveUniformsiv glad_glGetActiveUniformsiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLAPI PFNGLGETACTIVEUNIFORMNAMEPROC glad_glGetActiveUniformName;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetActiveUniformName'>OpenGL 4</a><br /><a  href='../gl3/glGetActiveUniformName'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glGetActiveUniformName</h1>
    <div class="refentry" id="glGetActiveUniformName">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetActiveUniformName — query the name of an active uniform</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetActiveUniformName</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">program</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">uniformIndex</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">bufSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei *<var class="pdparam">length</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLchar *<var class="pdparam">uniformName</var><code>)</code>;</td>
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
                  <code>program</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the program containing the active uniform index <em class="parameter"><code>uniformIndex</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformIndex</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the index of the active uniform whose name to query.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>bufSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the size of the buffer, in units of <code class="code">GLchar</code>, of the buffer whose address is specified in <em class="parameter"><code>uniformName</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>length</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of a variable that will receive the number of characters that were or would have been written to the buffer addressed by <em class="parameter"><code>uniformName</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformName</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of a buffer into which the GL will place the name of the active uniform at <em class="parameter"><code>uniformIndex</code></em> within <em class="parameter"><code>program</code></em>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetActiveUniformName</code> returns the name of the active uniform at <em class="parameter"><code>uniformIndex</code></em> within <em class="parameter"><code>program</code></em>.
            If <em class="parameter"><code>uniformName</code></em> is not <code class="code">NULL</code>, up to <em class="parameter"><code>bufSize</code></em> characters (including a nul-terminator) will be written into
            the array whose address is specified by <em class="parameter"><code>uniformName</code></em>. If <em class="parameter"><code>length</code></em> is not <code class="code">NULL</code>, the number of characters
            that were (or would have been) written into <em class="parameter"><code>uniformName</code></em> (not including the nul-terminator) will be placed in the variable whose address
            is specified in <em class="parameter"><code>length</code></em>. If <em class="parameter"><code>length</code></em> is <code class="code">NULL</code>, no length is returned. The length of the longest uniform
            name in <em class="parameter"><code>program</code></em> is given by the value of <code class="constant">GL_ACTIVE_UNIFORM_MAX_LENGTH</code>, which can be queried with
            <a class="citerefentry" href="glGetProgram"><span class="citerefentry"><span class="refentrytitle">glGetProgram</span></span></a>.
        </p>
        <p>
            If <code class="function">glGetActiveUniformName</code> is not successful, nothing is written to <em class="parameter"><code>length</code></em> or <em class="parameter"><code>uniformName</code></em>.
        </p>
        <p>
            <em class="parameter"><code>program</code></em> must be the name of a program for which the command <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a>
            has been issued in the past. It is not necessary for <em class="parameter"><code>program</code></em> to have been linked successfully. The link could have failed because
            the number of active uniforms exceeded the limit.
        </p>
        <p>
            <em class="parameter"><code>uniformIndex</code></em> must be an active uniform
            index of the program <em class="parameter"><code>program</code></em>, in the
            range zero to the value of
            <code class="constant">GL_ACTIVE_UNIFORMS</code> minus one. The value of
            <code class="constant">GL_ACTIVE_UNIFORMS</code> can be queried with
            <a class="citerefentry" href="glGetProgram"><span class="citerefentry"><span class="refentrytitle">glGetProgram</span></span></a>.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>uniformIndex</code></em> is greater than or equal to the value
            of <code class="constant">GL_ACTIVE_UNIFORMS</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>bufSize</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>program</code></em> is not the name of a program object for which
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> has been issued.
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
                  <code class="function">glGetActiveUniformName</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glGetActiveUniform"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniform</span></span></a>,
            <a class="citerefentry" href="glGetUniformIndices"><span class="citerefentry"><span class="refentrytitle">glGetUniformIndices</span></span></a>,
            <a class="citerefentry" href="glGetProgram"><span class="citerefentry"><span class="refentrytitle">glGetProgram</span></span></a>,
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetActiveUniformName.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetActiveUniformName glad_glGetActiveUniformName
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar *uniformBlockName);
GLAPI PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetUniformBlockIndex'>OpenGL 4</a><br /><a  href='../gl3/glGetUniformBlockIndex'>OpenGL 3</a><br /><a  href='../es3/glGetUniformBlockIndex'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glGetUniformBlockIndex</h1>
    <div class="refentry" id="glGetUniformBlockIndex">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetUniformBlockIndex — retrieve the index of a named uniform block</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">GLuint <strong class="fsfunc">glGetUniformBlockIndex</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">program</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLchar *<var class="pdparam">uniformBlockName</var><code>)</code>;</td>
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
                  <code>program</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of a program containing the uniform block.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformBlockName</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address an array of characters to containing the name of the uniform block whose index to retrieve.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetUniformBlockIndex</code> retrieves the index of a uniform block within <em class="parameter"><code>program</code></em>.
        </p>
        <p>
            <em class="parameter"><code>program</code></em> must be the name of a program object for which the command
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> must have been called in the past, although it is not required that
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> must have succeeded. The link could have failed because the number
            of active uniforms exceeded the limit.
        </p>
        <p>
            <em class="parameter"><code>uniformBlockName</code></em> must contain a nul-terminated string specifying the name of the uniform block.
        </p>
        <p>
            <code class="function">glGetUniformBlockIndex</code> returns the uniform block index for the uniform block named <em class="parameter"><code>uniformBlockName</code></em>
            of <em class="parameter"><code>program</code></em>. If <em class="parameter"><code>uniformBlockName</code></em> does not identify an active uniform block of <em class="parameter"><code>program</code></em>,
            <code class="function">glGetUniformBlockIndex</code> returns the special identifier, <code class="constant">GL_INVALID_INDEX</code>. Indices of the active uniform
            blocks of a program are assigned in consecutive order, beginning with zero.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>program</code></em> is not the name of a program object for which
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> has been called in the past.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glGetUniformBlockIndex</code> is available only if the GL version is 3.1 or greater.
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
                  <code class="function">glGetUniformBlockIndex</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glGetActiveUniformBlockName"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniformBlockName</span></span></a>,
            <a class="citerefentry" href="glGetActiveUniformBlock"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniformBlock</span></span></a>,
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetUniformBlockIndex.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetUniformBlockIndex glad_glGetUniformBlockIndex
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLAPI PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetActiveUniformBlock'>OpenGL 4</a><br /><a  href='../gl3/glGetActiveUniformBlock'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glGetActiveUniformBlock</h1>
    <div class="refentry" id="glGetActiveUniformBlock">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetActiveUniformBlock — query information about an active uniform block</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetActiveUniformBlockiv</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">program</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">uniformBlockIndex</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint *<var class="pdparam">params</var><code>)</code>;</td>
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
                  <code>program</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of a program containing the uniform block.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformBlockIndex</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the index of the uniform block within <em class="parameter"><code>program</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pname</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of the parameter to query.
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
                    Specifies the address of a variable to receive the result of the query.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetActiveUniformBlockiv</code> retrieves information about an active uniform block within <em class="parameter"><code>program</code></em>.
        </p>
        <p>
            <em class="parameter"><code>program</code></em> must be the name of a program object for which the command
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> must have been called in the past, although it is not required that
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> must have succeeded. The link could have failed because the number
            of active uniforms exceeded the limit.
        </p>
        <p>
            <em class="parameter"><code>uniformBlockIndex</code></em> is an active uniform block index of <em class="parameter"><code>program</code></em>, and must be less than the value
            of <code class="constant">GL_ACTIVE_UNIFORM_BLOCKS</code>.
        </p>
        <p>
            Upon success, the uniform block parameter(s) specified by <em class="parameter"><code>pname</code></em> are returned in <em class="parameter"><code>params</code></em>. If an error
            occurs, nothing will be written to <em class="parameter"><code>params</code></em>.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_BLOCK_BINDING</code>, then the index of the uniform buffer binding point
            last selected by the uniform block specified by <em class="parameter"><code>uniformBlockIndex</code></em> for <em class="parameter"><code>program</code></em> is returned. If
            no uniform block has been previously specified, zero is returned.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_BLOCK_DATA_SIZE</code>, then the implementation-dependent minimum total buffer
            object size, in basic machine units, required to hold all active uniforms in the uniform block identified by <em class="parameter"><code>uniformBlockIndex</code></em>
            is returned. It is neither guaranteed nor expected that a given implementation will arrange uniform values as tightly packed in a buffer
            object. The exception to this is the <span class="emphasis"><em>std140 uniform block layout</em></span>, which guarantees specific packing behavior and does not
            require the application to query for offsets and strides. In this case the minimum size may still be queried, even though it is determined in
            advance based only on the uniform block declaration.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_BLOCK_NAME_LENGTH</code>, then the total length (including the nul terminator) of
            the name of the uniform block identified by <em class="parameter"><code>uniformBlockIndex</code></em> is returned.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS</code>, then the number of active uniforms in the uniform
            block identified by <em class="parameter"><code>uniformBlockIndex</code></em> is returned.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES</code>, then a list of the active uniform indices
            for the uniform block identified by <em class="parameter"><code>uniformBlockIndex</code></em> is returned. The number of elements that will be written to
            <em class="parameter"><code>params</code></em> is the value of <code class="constant">GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS</code> for <em class="parameter"><code>uniformBlockIndex</code></em>.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER</code>, <code class="constant">GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER</code>,
            <code class="constant">GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER</code>, <code class="constant">GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER</code>,
            <code class="constant">GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER</code>, or <code class="constant">GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER</code>
            then a boolean value indicating whether the uniform block identified by
            <em class="parameter"><code>uniformBlockIndex</code></em> is referenced by the vertex, tessellation control, tessellation evaluation, geometry, fragment or compute
            programming stages of program, respectively, is returned.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>uniformBlockIndex</code></em> is greater than or equal to the value
            of <code class="constant">GL_ACTIVE_UNIFORM_BLOCKS</code> or is not the index of an active uniform block in <em class="parameter"><code>program</code></em>.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>pname</code></em> is not one of the accepted tokens.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>program</code></em> is not the name of a program object for which
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> has been called in the past.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glGetActiveUniformBlockiv</code> is available only if the GL version is 3.1 or greater.
        </p>
        <p>
            <code class="constant">GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER</code> is accepted only if the GL version is 4.3
            or greater.
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
                  <code class="function">glGetActiveUniformBlockiv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glGetActiveUniformBlockName"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniformBlockName</span></span></a>,
            <a class="citerefentry" href="glGetUniformBlockIndex"><span class="citerefentry"><span class="refentrytitle">glGetUniformBlockIndex</span></span></a>,
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetActiveUniformBlock.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetActiveUniformBlockiv glad_glGetActiveUniformBlockiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLAPI PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetActiveUniformBlockName'>OpenGL 4</a><br /><a  href='../gl3/glGetActiveUniformBlockName'>OpenGL 3</a><br /><a  href='../es3/glGetActiveUniformBlockName'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glGetActiveUniformBlockName</h1>
    <div class="refentry" id="glGetActiveUniformBlockName">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetActiveUniformBlockName — retrieve the name of an active uniform block</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetActiveUniformBlockName</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">program</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">uniformBlockIndex</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">bufSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei *<var class="pdparam">length</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLchar *<var class="pdparam">uniformBlockName</var><code>)</code>;</td>
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
                  <code>program</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of a program containing the uniform block.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformBlockIndex</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the index of the uniform block within <em class="parameter"><code>program</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>bufSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the size of the buffer addressed by <em class="parameter"><code>uniformBlockName</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>length</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of a variable to receive the number of characters that were written to <em class="parameter"><code>uniformBlockName</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformBlockName</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address an array of characters to receive the name of the uniform block at <em class="parameter"><code>uniformBlockIndex</code></em>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetActiveUniformBlockName</code> retrieves the name of the active uniform block at <em class="parameter"><code>uniformBlockIndex</code></em>
            within <em class="parameter"><code>program</code></em>.
        </p>
        <p>
            <em class="parameter"><code>program</code></em> must be the name of a program object for which the command
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> must have been called in the past, although it is not required that
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> must have succeeded. The link could have failed because the number
            of active uniforms exceeded the limit.
        </p>
        <p>
            <em class="parameter"><code>uniformBlockIndex</code></em> is an active uniform block index of <em class="parameter"><code>program</code></em>, and must be less than the value
            of <code class="constant">GL_ACTIVE_UNIFORM_BLOCKS</code>.
        </p>
        <p>
            Upon success, the name of the uniform block identified by <em class="parameter"><code>unifomBlockIndex</code></em> is returned into
            <em class="parameter"><code>uniformBlockName</code></em>. The name is nul-terminated. The actual number of characters written into <em class="parameter"><code>uniformBlockName</code></em>,
            excluding the nul terminator, is returned in <em class="parameter"><code>length</code></em>. If <em class="parameter"><code>length</code></em> is <code class="code">NULL</code>, no length is returned.
        </p>
        <p>
            <em class="parameter"><code>bufSize</code></em> contains the maximum number of characters (including the nul terminator) that will be written into
            <em class="parameter"><code>uniformBlockName</code></em>.
        </p>
        <p>
            If an error occurs, nothing will be written to <em class="parameter"><code>uniformBlockName</code></em> or <em class="parameter"><code>length</code></em>.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>program</code></em> is not the name of a program object for which
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> has been called in the past.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>uniformBlockIndex</code></em> is greater than or equal to the value
            of <code class="constant">GL_ACTIVE_UNIFORM_BLOCKS</code> or is not the index of an active uniform block in <em class="parameter"><code>program</code></em>.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glGetActiveUniformBlockName</code> is available only if the GL version is 3.1 or greater.
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
                  <code class="function">glGetActiveUniformBlockName</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glGetActiveUniformBlock"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniformBlock</span></span></a>,
            <a class="citerefentry" href="glGetUniformBlockIndex"><span class="citerefentry"><span class="refentrytitle">glGetUniformBlockIndex</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetActiveUniformBlockName.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetActiveUniformBlockName glad_glGetActiveUniformBlockName
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
GLAPI PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glUniformBlockBinding'>OpenGL 4</a><br /><a  href='../gl3/glUniformBlockBinding'>OpenGL 3</a><br /><a  href='../es3/glUniformBlockBinding'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glUniformBlockBinding</h1>
    <div class="refentry" id="glUniformBlockBinding">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glUniformBlockBinding — assign a binding point to an active uniform block</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glUniformBlockBinding</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">program</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">uniformBlockIndex</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">uniformBlockBinding</var><code>)</code>;</td>
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
                  <code>program</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    The name of a program object containing the active uniform block whose binding to assign.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformBlockIndex</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    The index of the active uniform block within <em class="parameter"><code>program</code></em> whose binding to assign.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>uniformBlockBinding</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the binding point to which to bind the uniform block with index <em class="parameter"><code>uniformBlockIndex</code></em> within <em class="parameter"><code>program</code></em>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Binding points for active uniform blocks are assigned using <code class="function">glUniformBlockBinding</code>. Each of a program's active uniform
            blocks has a corresponding uniform buffer binding point. <em class="parameter"><code>program</code></em> is the name of a program object for which the command
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a> has been issued in the past.
        </p>
        <p>
            If successful, <code class="function">glUniformBlockBinding</code> specifies that <em class="parameter"><code>program</code></em> will use the data store of the
            buffer object bound to the binding point <em class="parameter"><code>uniformBlockBinding</code></em> to extract the values of the uniforms in the
            uniform block identified by <em class="parameter"><code>uniformBlockIndex</code></em>.
        </p>
        <p>
            When a program object is linked or re-linked, the uniform buffer object binding point assigned to each of its active uniform blocks is reset to zero.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>uniformBlockIndex</code></em> is not an active uniform block index of <em class="parameter"><code>program</code></em>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>uniformBlockBinding</code></em> is greater than or equal to the value of <code class="constant">GL_MAX_UNIFORM_BUFFER_BINDINGS</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>program</code></em> is not the name of a program object generated by the GL.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glUniformBlockBinding</code> is available only if the GL version is 3.1 or greater.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetActiveUniformBlock"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniformBlock</span></span></a> with argument <code class="constant">GL_UNIFORM_BLOCK_BINDING</code>
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
                  <code class="function">glUniformBlockBinding</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glLinkProgram"><span class="citerefentry"><span class="refentrytitle">glLinkProgram</span></span></a>,
            <a class="citerefentry" href="glBindBufferBase"><span class="citerefentry"><span class="refentrytitle">glBindBufferBase</span></span></a>,
            <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>,
            <a class="citerefentry" href="glGetActiveUniformBlock"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniformBlock</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glUniformBlockBinding.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glUniformBlockBinding glad_glUniformBlockBinding
#endif
#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
GLAPI int GLAD_GL_VERSION_3_2;
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDrawElementsBaseVertex'>OpenGL 4</a><br /><a  href='../gl3/glDrawElementsBaseVertex'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glDrawElementsBaseVertex</h1>
    <div class="refentry" id="glDrawElementsBaseVertex">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDrawElementsBaseVertex — render primitives from array data with a per-element offset</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDrawElementsBaseVertex</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
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
              <td>GLvoid *<var class="pdparam">indices</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">basevertex</var><code>)</code>;</td>
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
                    <code class="constant">GL_POINTS</code>, <code class="constant">GL_LINE_STRIP</code>, <code class="constant">GL_LINE_LOOP</code>,
                    <code class="constant">GL_LINES</code>, <code class="constant">GL_TRIANGLE_STRIP</code>, <code class="constant">GL_TRIANGLE_FAN</code>,
                    <code class="constant">GL_TRIANGLES</code>, <code class="constant">GL_LINES_ADJACENCY</code>, <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code>, <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code> and <code class="constant">GL_PATCHES</code> are accepted.
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
                    Specifies the type of the values in indices. Must be one of <code class="constant">GL_UNSIGNED_BYTE</code>,
                    <code class="constant">GL_UNSIGNED_SHORT</code>, or <code class="constant">GL_UNSIGNED_INT</code>.
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
                  <code>basevertex</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a constant that should be added to each element of <em class="parameter"><code>indices</code></em>
                    when chosing elements from the enabled vertex arrays.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDrawElementsBaseVertex</code> behaves identically to
            <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a> except that the <span class="emphasis"><em>i</em></span>th element
            transferred by the corresponding draw call will be taken from element <em class="parameter"><code>indices</code></em>[i] + <em class="parameter"><code>basevertex</code></em>
            of each enabled array. If the resulting value is larger than the maximum value representable by <em class="parameter"><code>type</code></em>,
            it is as if the calculation were upconverted to 32-bit unsigned integers (with wrapping on overflow conditions).
            The operation is undefined if the sum would be negative.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glDrawElementsBaseVertex</code> is only supported
            if the GL version is 3.2 or greater, or if the
            <code class="code">ARB_draw_elements_base_vertex</code> extension is
            supported.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>count</code></em> is negative.
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
                  <code class="function">glDrawElementsBaseVertex</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElementsBaseVertex</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstanced</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstancedBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstancedBaseVertex</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDrawElementsBaseVertex.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glDrawElementsBaseVertex glad_glDrawElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDrawRangeElementsBaseVertex'>OpenGL 4</a><br /><a  href='../gl3/glDrawRangeElementsBaseVertex'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glDrawRangeElementsBaseVertex</h1>
    <div class="refentry" id="glDrawRangeElementsBaseVertex">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDrawRangeElementsBaseVertex — render primitives from array data with a per-element offset</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDrawRangeElementsBaseVertex</strong>(</code>
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
              <td>GLvoid *<var class="pdparam">indices</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">basevertex</var><code>)</code>;</td>
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
                    <code class="constant">GL_POINTS</code>, <code class="constant">GL_LINE_STRIP</code>, <code class="constant">GL_LINE_LOOP</code>,
                    <code class="constant">GL_LINES</code>, <code class="constant">GL_TRIANGLE_STRIP</code>, <code class="constant">GL_TRIANGLE_FAN</code>,
                    <code class="constant">GL_TRIANGLES</code>, <code class="constant">GL_LINES_ADJACENCY</code>, <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code>, <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code> and <code class="constant">GL_PATCHES</code> are accepted.
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
                    Specifies the type of the values in indices. Must be one of <code class="constant">GL_UNSIGNED_BYTE</code>,
                    <code class="constant">GL_UNSIGNED_SHORT</code>, or <code class="constant">GL_UNSIGNED_INT</code>.
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
                  <code>basevertex</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a constant that should be added to each element of <em class="parameter"><code>indices</code></em>
                    when chosing elements from the enabled vertex arrays.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDrawRangeElementsBaseVertex</code> is a restricted form of
            <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>. <em class="parameter"><code>mode</code></em>,
            <em class="parameter"><code>start</code></em>, <em class="parameter"><code>end</code></em>, <em class="parameter"><code>count</code></em> and <em class="parameter"><code>basevertex</code></em> match
            the corresponding arguments to <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>, with the additional
            constraint that all values in the array <em class="parameter"><code>indices</code></em> must lie between <em class="parameter"><code>start</code></em> and <em class="parameter"><code>end</code></em>,
            inclusive, prior to adding <em class="parameter"><code>basevertex</code></em>. Index values lying outside the range [<em class="parameter"><code>start</code></em>, <em class="parameter"><code>end</code></em>]
            are treated in the same way as <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>. The <span class="emphasis"><em>i</em></span>th element
            transferred by the corresponding draw call will be taken from element <em class="parameter"><code>indices</code></em>[i] + <em class="parameter"><code>basevertex</code></em> of each enabled
            array. If the resulting value is larger than the maximum value representable by <em class="parameter"><code>type</code></em>, it is as if the calculation were upconverted to
            32-bit unsigned integers (with wrapping on overflow conditions). The operation is undefined if the sum would be negative.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>count</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>end</code></em> &lt; <em class="parameter"><code>start</code></em>.
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
                  <code class="function">glDrawRangeElementsBaseVertex</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstanced</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstancedBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstancedBaseVertex</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDrawRangeElementsBaseVertex.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glDrawRangeElementsBaseVertex glad_glDrawRangeElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDrawElementsInstancedBaseVertex'>OpenGL 4</a><br /><a  href='../gl3/glDrawElementsInstancedBaseVertex'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glDrawElementsInstancedBaseVertex</h1>
    <div class="refentry" id="glDrawElementsInstancedBaseVertex">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDrawElementsInstancedBaseVertex — render multiple instances of a set of primitives from array data with a per-element offset</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDrawElementsInstancedBaseVertex</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
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
              <td>GLvoid *<var class="pdparam">indices</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">primcount</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">basevertex</var><code>)</code>;</td>
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
                    <code class="constant">GL_POINTS</code>, <code class="constant">GL_LINE_STRIP</code>, <code class="constant">GL_LINE_LOOP</code>,
                    <code class="constant">GL_LINES</code>, <code class="constant">GL_TRIANGLE_STRIP</code>, <code class="constant">GL_TRIANGLE_FAN</code>,
                    <code class="constant">GL_TRIANGLES</code>, <code class="constant">GL_LINES_ADJACENCY</code>, <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code>, <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code> and <code class="constant">GL_PATCHES</code> are accepted.
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
                    Specifies the type of the values in indices. Must be one of <code class="constant">GL_UNSIGNED_BYTE</code>,
                    <code class="constant">GL_UNSIGNED_SHORT</code>, or <code class="constant">GL_UNSIGNED_INT</code>.
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
                  <code>primcount</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of instances of the indexed geometry that should be drawn.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>basevertex</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a constant that should be added to each element of <em class="parameter"><code>indices</code></em>
                    when chosing elements from the enabled vertex arrays.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDrawElementsInstancedBaseVertex</code> behaves identically to
            <a class="citerefentry" href="glDrawElementsInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstanced</span></span></a> except that the <span class="emphasis"><em>i</em></span>th element
            transferred by the corresponding draw call will be taken from element <em class="parameter"><code>indices</code></em>[i] + <em class="parameter"><code>basevertex</code></em>
            of each enabled array. If the resulting value is larger than the maximum value representable by <em class="parameter"><code>type</code></em>,
            it is as if the calculation were upconverted to 32-bit unsigned integers (with wrapping on overflow conditions).
            The operation is undefined if the sum would be negative.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glDrawElementsInstancedBaseVertex</code> is only supported if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>count</code></em> or <em class="parameter"><code>primcount</code></em> is negative.
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
                  <code class="function">glDrawElementsInstancedBaseVertex</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElementsBaseVertex</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstanced</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstancedBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstancedBaseVertex</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDrawElementsInstancedBaseVertex.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glDrawElementsInstancedBaseVertex glad_glDrawElementsInstancedBaseVertex
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLAPI PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glad_glMultiDrawElementsBaseVertex;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glMultiDrawElementsBaseVertex'>OpenGL 4</a><br /><a  href='../gl3/glMultiDrawElementsBaseVertex'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glMultiDrawElementsBaseVertex</h1>
    <div class="refentry" id="glMultiDrawElementsBaseVertex">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glMultiDrawElementsBaseVertex — render multiple sets of primitives by specifying indices of array data elements and an index to apply to each index</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glMultiDrawElementsBaseVertex</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLsizei *<var class="pdparam">count</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * const *<var class="pdparam">indices</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">drawcount</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLint *<var class="pdparam">basevertex</var><code>)</code>;</td>
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
                    Specifies the size of the <em class="parameter"><code>count</code></em>, <em class="parameter"><code>indices</code></em> and <em class="parameter"><code>basevertex</code></em> arrays.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>basevertex</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the location where the base vertices are stored.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glMultiDrawElementsBaseVertex</code> behaves identically to <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>,
            except that <em class="parameter"><code>drawcount</code></em> separate lists of elements are specifried instead.
        </p>
        <p>
        It has the same effect as:
        </p>
        <pre class="programlisting">    for (int i = 0; i &lt; <em class="parameter"><code>drawcount</code></em>; i++)
        if (<em class="parameter"><code>count</code></em>[i] &gt; 0)
            glDrawElementsBaseVertex(<em class="parameter"><code>mode</code></em>,
                                     <em class="parameter"><code>count</code></em>[i],
                                     <em class="parameter"><code>type</code></em>,
                                     <em class="parameter"><code>indices[i]</code></em>,
                                     <em class="parameter"><code>basevertex[i]</code></em>);</pre>
        <p>
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glMultiDrawElementsBaseVertex</code> is available only if the GL version is 3.1 or greater.
        </p>
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
                  <code class="function">glMultiDrawElementsBaseVertex</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glMultiDrawElements"><span class="citerefentry"><span class="refentrytitle">glMultiDrawElements</span></span></a>,
            <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>,
            <a class="citerefentry" href="glDrawArrays"><span class="citerefentry"><span class="refentrytitle">glDrawArrays</span></span></a>,
            <a class="citerefentry" href="glVertexAttribPointer"><span class="citerefentry"><span class="refentrytitle">glVertexAttribPointer</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glMultiDrawElementsBaseVertex.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glMultiDrawElementsBaseVertex glad_glMultiDrawElementsBaseVertex
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
GLAPI PFNGLPROVOKINGVERTEXPROC glad_glProvokingVertex;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glProvokingVertex'>OpenGL 4</a><br /><a  href='../gl3/glProvokingVertex'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glProvokingVertex</h1>
    <div class="refentry" id="glProvokingVertex">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glProvokingVertex — specifiy the vertex to be used as the source of data for flat shaded varyings</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glProvokingVertex</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">provokeMode</var><code>)</code>;</td>
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
                  <code>provokeMode</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the vertex to be used as the source of data for flat shaded varyings.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <span class="emphasis"><em>Flatshading</em></span> a vertex shader varying output means to assign all vetices of the primitive the same value
            for that output. The vertex from which these values is derived is known as the <span class="emphasis"><em>provoking vertex</em></span> and
            <code class="function">glProvokingVertex</code> specifies which vertex is to be used as the source of data for flat shaded varyings.
        </p>
        <p>
            <em class="parameter"><code>provokeMode</code></em> must be either <code class="constant">GL_FIRST_VERTEX_CONVENTION</code> or
            <code class="constant">GL_LAST_VERTEX_CONVENTION</code>, and controls the selection of the vertex whose values are assigned to flatshaded
            varying outputs. The interpretation of these values for the supported primitive types is:
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
                                <span class="bold"><strong> Primitive Type of Polygon <span class="emphasis"><em>i</em></span> </strong></span>
                            </th>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; "><span class="bold"><strong> First Vertex Convention </strong></span>
                            </th>
                <th style="text-align: left; border-bottom: 2px solid ; ">
                                <span class="bold"><strong> Last Vertex Convention </strong></span>
                            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                point
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span>
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span>
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                independent line
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                2<span class="emphasis"><em>i</em></span> - 1
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                2<span class="emphasis"><em>i</em></span>
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                line loop
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span>
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                <p>
                                <span class="emphasis"><em>i</em></span> + 1, if <span class="emphasis"><em>i</em></span> &lt; <span class="emphasis"><em>n</em></span>
                                </p>
                                <p>
                                1, if <span class="emphasis"><em>i</em></span> = <span class="emphasis"><em>n</em></span>
                                </p>
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                line strip
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span>
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span> + 1
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                independent triangle
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                3<span class="emphasis"><em>i</em></span> - 2
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                3<span class="emphasis"><em>i</em></span>
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                triangle strip
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span>
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span> + 2
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                triangle fan
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span> + 1
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span> + 2
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                line adjacency
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                4<span class="emphasis"><em>i</em></span> - 2
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                4<span class="emphasis"><em>i</em></span> - 1
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                line strip adjacency
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span> + 1
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                <span class="emphasis"><em>i</em></span> + 2
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                triangle adjacency
                            </td>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                                6<span class="emphasis"><em>i</em></span> - 5
                            </td>
                <td style="text-align: left; border-bottom: 2px solid ; ">
                                6<span class="emphasis"><em>i</em></span> - 1
                            </td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                                triangle strip adjacency
                            </td>
                <td style="text-align: left; border-right: 2px solid ; ">
                                2<span class="emphasis"><em>i</em></span> - 1
                            </td>
                <td style="text-align: left; ">
                                2<span class="emphasis"><em>i</em></span> + 3
                            </td>
              </tr>
            </tbody>
          </table>
        </div>
        <p>
        </p>
        <p>
            If a vertex or geometry shader is active, user-defined varying outputs may be flatshaded by using the
            <code class="code">flat</code> qualifier when declaring the output.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glProvokingVertex</code> is available only if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>provokeMode</code></em> is not an accepted value.
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
                  <code class="function">glProvokingVertex</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glProvokingVertex.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glProvokingVertex glad_glProvokingVertex
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
GLAPI PFNGLFENCESYNCPROC glad_glFenceSync;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glFenceSync'>OpenGL 4</a><br /><a  href='../gl3/glFenceSync'>OpenGL 3</a><br /><a  href='../es3/glFenceSync'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glFenceSync</h1>
    <div class="refentry" id="glFenceSync">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glFenceSync — create a new sync object and insert it into the GL command stream</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">GLsync <strong class="fsfunc">glFenceSync</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">condition</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLbitfield <var class="pdparam">flags</var><code>)</code>;</td>
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
                  <code>condition</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the condition that must be met to set the sync object's state to signaled. <em class="parameter"><code>condition</code></em>
                    must be <code class="constant">GL_SYNC_GPU_COMMANDS_COMPLETE</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>flags</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a bitwise combination of flags controlling the behavior of the sync object. No flags are presently defined
                    for this operation and <em class="parameter"><code>flags</code></em> must be zero.<a href="#ftn.idp170352" class="footnote"><sup class="footnote" id="idp170352">[1]</sup></a>
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glFenceSync</code> creates a new fence sync object, inserts a fence command into the GL command stream and
            associates it with that sync object, and returns a non-zero name corresponding to the sync object.
        </p>
        <p>
            When the specified <em class="parameter"><code>condition</code></em> of the sync object is satisfied by the fence command, the sync object
            is signaled by the GL, causing any <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a>,
            <a class="citerefentry" href="glClientWaitSync"><span class="citerefentry"><span class="refentrytitle">glClientWaitSync</span></span></a> commands blocking in <em class="parameter"><code>sync</code></em>
            to <span class="emphasis"><em>unblock</em></span>. No other state is affected by <code class="function">glFenceSync</code> or by the execution
            of the associated fence command.
        </p>
        <p>
            <em class="parameter"><code>condition</code></em> must be <code class="constant">GL_SYNC_GPU_COMMANDS_COMPLETE</code>. This condition is satisfied by
            completion of the fence command corresponding to the sync object and all preceding commands in the same command stream.
            The sync object will not be signaled until all effects from these commands on GL client and server state and the
            framebuffer are fully realized. Note that completion of the fence command occurs once the state of the corresponding sync
            object has been changed, but commands waiting on that sync object may not be unblocked until after the fence command completes.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glFenceSync</code> is only supported if the GL version is 3.2 or greater, or if
            the <code class="code">ARB_sync</code> extension is supported.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>condition</code></em> is not
            <code class="constant">GL_SYNC_GPU_COMMANDS_COMPLETE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>flags</code></em> is not zero.
        </p>
        <p>
            Additionally, if <code class="function">glFenceSync</code> fails, it will return zero.
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
                  <code class="function">glFenceSync</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glDeleteSync"><span class="citerefentry"><span class="refentrytitle">glDeleteSync</span></span></a>,
            <a class="citerefentry" href="glGetSync"><span class="citerefentry"><span class="refentrytitle">glGetSync</span></span></a>,
            <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a>,
            <a class="citerefentry" href="glClientWaitSync"><span class="citerefentry"><span class="refentrytitle">glClientWaitSync</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
      <div class="footnotes">
        <br/>
        <hr class="footnote-hr"/>
        <div id="ftn.idp170352" class="footnote">
          <p><a href="#idp170352" class="para"><sup class="para">[1] </sup></a>
                        <em class="parameter"><code>flags</code></em> is a placeholder for anticipated future extensions of fence sync object capabilities.
                        </p>
        </div>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glFenceSync.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glFenceSync glad_glFenceSync
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
GLAPI PFNGLISSYNCPROC glad_glIsSync;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glIsSync'>OpenGL 4</a><br /><a  href='../gl3/glIsSync'>OpenGL 3</a><br /><a  href='../es3/glIsSync'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glIsSync</h1>
    <div class="refentry" id="glIsSync">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glIsSync — determine if a name corresponds to a sync object</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">GLboolean <strong class="fsfunc">glIsSync</strong>(</code>
              </td>
              <td>GLsync <var class="pdparam">sync</var><code>)</code>;</td>
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
                  <code>sync</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a value that may be the name of a sync object.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glIsSync</code> returns <code class="constant">GL_TRUE</code> if <em class="parameter"><code>sync</code></em> is currently the name of a sync object.
            If <em class="parameter"><code>sync</code></em> is not the name of a sync object, or if an error occurs, <code class="function">glIsSync</code> returns
            <code class="constant">GL_FALSE</code>. Note that zero is not the name of a sync object.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glIsSync</code> is available only if the GL version is 3.2 or greater.
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
                  <code class="function">glIsSync</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glFenceSync"><span class="citerefentry"><span class="refentrytitle">glFenceSync</span></span></a>,
            <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a>,
            <a class="citerefentry" href="glClientWaitSync"><span class="citerefentry"><span class="refentrytitle">glClientWaitSync</span></span></a>,
            <a class="citerefentry" href="glDeleteSync"><span class="citerefentry"><span class="refentrytitle">glDeleteSync</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glIsSync.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glIsSync glad_glIsSync
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
GLAPI PFNGLDELETESYNCPROC glad_glDeleteSync;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDeleteSync'>OpenGL 4</a><br /><a  href='../gl3/glDeleteSync'>OpenGL 3</a><br /><a  href='../es3/glDeleteSync'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glDeleteSync</h1>
    <div class="refentry" id="glDeleteSync">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDeleteSync — delete a sync object</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDeleteSync</strong>(</code>
              </td>
              <td>GLsync <var class="pdparam">sync</var><code>)</code>;</td>
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
                  <code>sync</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    The sync object to be deleted.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDeleteSync</code> deletes the sync object specified by <em class="parameter"><code>sync</code></em>. If the fence command
            corresponding to the specified sync object has completed, or if no <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a>
            or <a class="citerefentry" href="glClientWaitSync"><span class="citerefentry"><span class="refentrytitle">glClientWaitSync</span></span></a> commands are blocking on <em class="parameter"><code>sync</code></em>,
            the object is deleted immediately. Otherwise, <em class="parameter"><code>sync</code></em> is flagged for deletion and will be deleted when
            it is no longer associated with any fence command and is no longer blocking any <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a>
            or <a class="citerefentry" href="glClientWaitSync"><span class="citerefentry"><span class="refentrytitle">glClientWaitSync</span></span></a> command. In either case, after
            <code class="function">glDeleteSync</code> returns, the name <em class="parameter"><code>sync</code></em> is invalid and can no longer be used to
            refer to the sync object.
        </p>
        <p>
            <code class="function">glDeleteSync</code> will silently ignore a <em class="parameter"><code>sync</code></em> value of zero.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glSync</code> is only supported if the GL version is 3.2 or greater, or if
            the <code class="code">ARB_sync</code> extension is supported.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>sync</code></em> is neither zero or the name of a sync object.
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
                  <code class="function">glDeleteSync</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glFenceSync"><span class="citerefentry"><span class="refentrytitle">glFenceSync</span></span></a>,
            <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a>,
            <a class="citerefentry" href="glClientWaitSync"><span class="citerefentry"><span class="refentrytitle">glClientWaitSync</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDeleteSync.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glDeleteSync glad_glDeleteSync
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glClientWaitSync'>OpenGL 4</a><br /><a  href='../gl3/glClientWaitSync'>OpenGL 3</a><br /><a  href='../es3/glClientWaitSync'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glClientWaitSync</h1>
    <div class="refentry" id="glClientWaitSync">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glClientWaitSync — block and wait for a sync object to become signaled</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">GLenum <strong class="fsfunc">glClientWaitSync</strong>(</code>
              </td>
              <td>GLsync <var class="pdparam">sync</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLbitfield <var class="pdparam">flags</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint64 <var class="pdparam">timeout</var><code>)</code>;</td>
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
                  <code>sync</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    The sync object whose status to wait on.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>flags</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    A bitfield controlling the command flushing behavior. <em class="parameter"><code>flags</code></em> may be <code class="constant">GL_SYNC_FLUSH_COMMANDS_BIT</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>timeout</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    The timeout, specified in nanoseconds, for which the implementation should wait for <em class="parameter"><code>sync</code></em> to become signaled.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glClientWaitSync</code> causes the client to block and wait for the sync object specified by <em class="parameter"><code>sync</code></em> to become signaled. If
            <em class="parameter"><code>sync</code></em> is signaled when <code class="function">glClientWaitSync</code> is called, <code class="function">glClientWaitSync</code> returns immediately, otherwise
            it will block and wait for up to <em class="parameter"><code>timeout</code></em> nanoseconds for <em class="parameter"><code>sync</code></em> to become signaled.
        </p>
        <p>
            The return value is one of four status values:
            </p>
        <div class="itemizedlist">
          <ul class="itemizedlist" style="list-style-type: disc; ">
            <li class="listitem">
              <p>
                        <code class="constant">GL_ALREADY_SIGNALED</code> indicates that <em class="parameter"><code>sync</code></em> was signaled at the time that <code class="function">glClientWaitSync</code>
                        was called.
                    </p>
            </li>
            <li class="listitem">
              <p>
                        <code class="constant">GL_TIMEOUT_EXPIRED</code> indicates that at least <em class="parameter"><code>timeout</code></em> nanoseconds passed and <em class="parameter"><code>sync</code></em> did not
                        become signaled.
                    </p>
            </li>
            <li class="listitem">
              <p>
                        <code class="constant">GL_CONDITION_SATISFIED</code> indicates that <em class="parameter"><code>sync</code></em> was signaled before the timeout expired.
                    </p>
            </li>
            <li class="listitem">
              <p>
                        <code class="constant">GL_WAIT_FAILED</code> indicates that an error occurred. Additionally, an OpenGL error will be generated.
                    </p>
            </li>
          </ul>
        </div>
        <p>
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glClientWaitSync</code> is available only if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>sync</code></em> is not the name of an existing sync object.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>flags</code></em> contains any unsupported flag.
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
                  <code class="function">glClientWaitSync</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glFenceSync"><span class="citerefentry"><span class="refentrytitle">glFenceSync</span></span></a>,
            <a class="citerefentry" href="glIsSync"><span class="citerefentry"><span class="refentrytitle">glIsSync</span></span></a>
            <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a>
            </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glClientWaitSync.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glClientWaitSync glad_glClientWaitSync
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI PFNGLWAITSYNCPROC glad_glWaitSync;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glWaitSync'>OpenGL 4</a><br /><a  href='../gl3/glWaitSync'>OpenGL 3</a><br /><a  href='../es3/glWaitSync'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glWaitSync</h1>
    <div class="refentry" id="glWaitSync">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glWaitSync — instruct the GL server to block until the specified sync object becomes signaled</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glWaitSync</strong>(</code>
              </td>
              <td>GLsync <var class="pdparam">sync</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLbitfield <var class="pdparam">flags</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint64 <var class="pdparam">timeout</var><code>)</code>;</td>
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
                  <code>sync</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the sync object whose status to wait on.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>flags</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    A bitfield controlling the command flushing behavior. <em class="parameter"><code>flags</code></em> may be zero.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>timeout</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the timeout that the server should wait before continuing. <em class="parameter"><code>timeout</code></em> must be <code class="constant">GL_TIMEOUT_IGNORED</code>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glWaitSync</code> causes the GL server to block and wait until <em class="parameter"><code>sync</code></em> becomes signaled. <em class="parameter"><code>sync</code></em>
            is the name of an existing sync object upon which to wait. <em class="parameter"><code>flags</code></em> and <em class="parameter"><code>timeout</code></em> are currently not used and
            must be set to zero and the special value <code class="constant">GL_TIMEOUT_IGNORED</code>, respectively<a href="#ftn.idp181536" class="footnote"><sup class="footnote" id="idp181536">[1]</sup></a>. <code class="function">glWaitSync</code> will always wait no longer than an implementation-dependent timeout. The
            duration of this timeout in nanoseconds may be queried by calling <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with the
            parameter <code class="constant">GL_MAX_SERVER_WAIT_TIMEOUT</code>. There is currently no way to determine whether <code class="function">glWaitSync</code> unblocked
            because the timeout expired or because the sync object being waited on was signaled.
        </p>
        <p>
            If an error occurs, <code class="function">glWaitSync</code> does not cause the GL server to block.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glWaitSync</code> is available only if the GL version is 3.2 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>sync</code></em> is not the name of a sync object.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>flags</code></em> is not zero.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>timeout</code></em> is not <code class="constant">GL_TIMEOUT_IGNORED</code>.
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
                  <code class="function">glWaitSync</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glFenceSync"><span class="citerefentry"><span class="refentrytitle">glFenceSync</span></span></a>,
            <a class="citerefentry" href="glClientWaitSync"><span class="citerefentry"><span class="refentrytitle">glClientWaitSync</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
      <div class="footnotes">
        <br/>
        <hr class="footnote-hr"/>
        <div id="ftn.idp181536" class="footnote">
          <p><a href="#idp181536" class="para"><sup class="para">[1] </sup></a><em class="parameter"><code>flags</code></em> and
            <em class="parameter"><code>timeout</code></em> are placeholders for anticipated future extensions of sync object capabilities. They must have these reserved values in
            order that existing code calling <code class="function">glWaitSync</code> operate properly in the presence of such extensions.</p>
        </div>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glWaitSync.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glWaitSync glad_glWaitSync
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 *data);
GLAPI PFNGLGETINTEGER64VPROC glad_glGetInteger64v;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGet'>OpenGL 4</a><br /><a  href='../gl3/glGet'>OpenGL 3</a><br /><a  href='../gl2/glGet'>OpenGL 2</a><br /><a  href='../es3/glGet'>OpenGL ES 3</a><br /><a  href='../es2/glGet'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glGet</h1>
    <div class="refentry" id="glGet">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGet — return the value or values of a selected parameter</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetBooleanv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLboolean * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetDoublev</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLdouble * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetFloatv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetIntegerv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetInteger64v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint64 * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetBooleani_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLboolean * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetIntegeri_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetFloati_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetDoublei_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLdouble * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetInteger64i_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint64 * <var class="pdparam">data</var><code>)</code>;</td>
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
                    Specifies the parameter value to be returned
                    for non-indexed versions of <code class="function">glGet</code>.
                    The symbolic constants in the list below are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the parameter value to be returned
                    for indexed versions of <code class="function">glGet</code>.
                    The symbolic constants in the list below are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>index</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the index of the particular element being queried.
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
                    Returns the value or values of the specified parameter.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            These commands return values for simple state variables in GL.
            <em class="parameter"><code>pname</code></em> is a symbolic constant indicating the state variable to be returned,
            and <em class="parameter"><code>data</code></em> is a pointer to an array of the indicated type in
            which to place the returned data.
        </p>
        <p>
            Type conversion is performed if <em class="parameter"><code>data</code></em> has a different type than
            the state variable value being requested.
            If <code class="function">glGetBooleanv</code> is called,
            a floating-point (or integer) value is converted to <code class="constant">GL_FALSE</code> if
            and only if it is 0.0 (or 0).
            Otherwise,
            it is converted to <code class="constant">GL_TRUE</code>.
            If <code class="function">glGetIntegerv</code> is called, boolean values are returned as
            <code class="constant">GL_TRUE</code> or <code class="constant">GL_FALSE</code>, and most floating-point values are
            rounded to the nearest integer value. Floating-point colors and
            normals, however, are returned with a linear mapping that maps 1.0 to
            the most positive representable integer value
            and
            <math overflow="scroll">

                <mn>-1.0</mn>
            </math>
            to the most negative representable integer value.
            If <code class="function">glGetFloatv</code> or <code class="function">glGetDoublev</code> is called,
            boolean values are returned as <code class="constant">GL_TRUE</code> or <code class="constant">GL_FALSE</code>,
            and integer values are converted to floating-point values.
        </p>
        <p>
            The following symbolic constants are accepted by <em class="parameter"><code>pname</code></em>:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_ACTIVE_TEXTURE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value indicating the active multitexture unit.
                        The initial value is <code class="constant">GL_TEXTURE0</code>.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_ALIASED_LINE_WIDTH_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a pair of values indicating the range of
                        widths supported for aliased lines. See <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_ARRAY_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_ARRAY_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether blending is
                        enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_COLOR</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns four values,
                        the red, green, blue, and alpha values which are the components of
                        the blend color.
                        See <a class="citerefentry" href="glBlendColor"><span class="citerefentry"><span class="refentrytitle">glBlendColor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_DST_ALPHA</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant identifying the alpha destination blend
                        function. The initial value is <code class="constant">GL_ZERO</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_DST_RGB</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant identifying the RGB destination blend
                        function. The initial value is <code class="constant">GL_ZERO</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_EQUATION_RGB</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, a symbolic constant indicating whether
                        the RGB blend equation is <code class="constant">GL_FUNC_ADD</code>, <code class="constant">GL_FUNC_SUBTRACT</code>,
                        <code class="constant">GL_FUNC_REVERSE_SUBTRACT</code>, <code class="constant">GL_MIN</code> or <code class="constant">GL_MAX</code>.
                        See <a class="citerefentry" href="glBlendEquationSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendEquationSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_EQUATION_ALPHA</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, a symbolic constant indicating whether
                        the Alpha blend equation is <code class="constant">GL_FUNC_ADD</code>, <code class="constant">GL_FUNC_SUBTRACT</code>,
                        <code class="constant">GL_FUNC_REVERSE_SUBTRACT</code>, <code class="constant">GL_MIN</code> or <code class="constant">GL_MAX</code>.
                        See <a class="citerefentry" href="glBlendEquationSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendEquationSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_SRC_ALPHA</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant identifying the alpha source blend function. The initial
                        value is <code class="constant">GL_ONE</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_SRC_RGB</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant identifying the RGB source blend function. The initial
                        value is <code class="constant">GL_ONE</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COLOR_CLEAR_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns four values:
                        the red, green, blue, and alpha values used to clear the color buffers.
                        Integer values,
                        if requested,
                        are linearly mapped from the internal floating-point representation such
                        that 1.0 returns the most positive representable integer value,
                        and
                        <math overflow="scroll">

                            <mn>-1.0</mn>
                        </math>
                        returns the most negative representable integer
                        value. The initial value is (0, 0, 0, 0).
                        See <a class="citerefentry" href="glClearColor"><span class="citerefentry"><span class="refentrytitle">glClearColor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COLOR_LOGIC_OP</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether a fragment's
                        RGBA color values are merged into the framebuffer using a logical
                        operation. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glLogicOp"><span class="citerefentry"><span class="refentrytitle">glLogicOp</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COLOR_WRITEMASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns four boolean values:
                        the red, green, blue, and alpha write enables for the color
                        buffers. The initial value is (<code class="constant">GL_TRUE</code>, <code class="constant">GL_TRUE</code>,
                        <code class="constant">GL_TRUE</code>, <code class="constant">GL_TRUE</code>).
                        See <a class="citerefentry" href="glColorMask"><span class="citerefentry"><span class="refentrytitle">glColorMask</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COMPRESSED_TEXTURE_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a list of symbolic
                        constants of length <code class="constant">GL_NUM_COMPRESSED_TEXTURE_FORMATS</code>
                        indicating which compressed texture formats are available.
                        See <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a compute shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum total number of active shader storage blocks that may be accessed by all active shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per compute shader.  The value must be at least 14.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the compute shader. The value may be at least 16.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual floating-point, integer, or boolean values that can be held
                        in uniform variable storage for a compute shader. The value must be at least 1024.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to compute shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counter buffers that may be accessed by a compute shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of words for compute shader uniform variables in all uniform
                        blocks (including default). The value must be at least 1.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of invocations in a single local work group
                        (i.e., the product of the three dimensions) that may
                        be dispatched to a compute shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_COUNT</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed versions of <code class="function">glGet</code>.
                        <em class="parameter"><code>data</code></em> the maximum number of work
                        groups that may be dispatched to a compute shader. Indices
                        0, 1, and 2 correspond to the X, Y and Z dimensions, respectively.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed versions of <code class="function">glGet</code>.
                        <em class="parameter"><code>data</code></em> the maximum size of a work
                        groups that may be used during compilation of a compute shader. Indices
                        0, 1, and 2 correspond to the X, Y and Z dimensions, respectively.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DISPATCH_INDIRECT_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_DISPATCH_INDIRECT_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_DEBUG_GROUP_STACK_DEPTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum depth of the
                        debug message group stack.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEBUG_GROUP_STACK_DEPTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the current depth of the
                        debug message group stack.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_CONTEXT_FLAGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the flags with which the context was created (such as debugging functionality).
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_CULL_FACE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether polygon culling
                        is enabled. The initial value is <code class="constant">GL_BACK</code>.
                        See <a class="citerefentry" href="glCullFace"><span class="citerefentry"><span class="refentrytitle">glCullFace</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_CURRENT_PROGRAM</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the name of the program object that is currently active, or 0 if no program object is active.
                        See <a class="citerefentry" href="glUseProgram"><span class="citerefentry"><span class="refentrytitle">glUseProgram</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_CLEAR_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the value that is used to clear the depth buffer.
                        Integer values,
                        if requested,
                        are linearly mapped from the internal floating-point representation such
                        that 1.0 returns the most positive representable integer value,
                        and
                        <math overflow="scroll">

                            <mn>-1.0</mn>
                        </math>
                        returns the most negative representable integer
                        value. The initial value is 1.
                        See <a class="citerefentry" href="glClearDepth"><span class="citerefentry"><span class="refentrytitle">glClearDepth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_FUNC</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant that indicates the depth comparison
                        function. The initial value is <code class="constant">GL_LESS</code>.
                        See <a class="citerefentry" href="glDepthFunc"><span class="citerefentry"><span class="refentrytitle">glDepthFunc</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns two values:
                        the near and far mapping limits for the depth buffer.
                        Integer values,
                        if requested,
                        are linearly mapped from the internal floating-point representation such
                        that 1.0 returns the most positive representable integer value,
                        and
                        <math overflow="scroll">

                            <mn>-1.0</mn>
                        </math>
                        returns the most negative representable integer
                        value. The initial value is (0, 1).
                        See <a class="citerefentry" href="glDepthRange"><span class="citerefentry"><span class="refentrytitle">glDepthRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether depth testing
                        of fragments is enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glDepthFunc"><span class="citerefentry"><span class="refentrytitle">glDepthFunc</span></span></a> and <a class="citerefentry" href="glDepthRange"><span class="citerefentry"><span class="refentrytitle">glDepthRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_WRITEMASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating if the depth buffer
                        is enabled for writing. The initial value is <code class="constant">GL_TRUE</code>.
                        See <a class="citerefentry" href="glDepthMask"><span class="citerefentry"><span class="refentrytitle">glDepthMask</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DITHER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether dithering of
                        fragment colors and indices is enabled. The initial value is <code class="constant">GL_TRUE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DOUBLEBUFFER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether double buffering
                        is supported.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DRAW_BUFFER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating which buffers are being drawn to.
                        See <a class="citerefentry" href="glDrawBuffer"><span class="citerefentry"><span class="refentrytitle">glDrawBuffer</span></span></a>. The initial value is <code class="constant">GL_BACK</code> if there
                        are back buffers, otherwise it is <code class="constant">GL_FRONT</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DRAW_BUFFER</code>
                <span class="emphasis">
                  <em>i</em>
                </span>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating which buffers are being drawn to by the corresponding output color.
                        See <a class="citerefentry" href="glDrawBuffers"><span class="citerefentry"><span class="refentrytitle">glDrawBuffers</span></span></a>.
                        The initial value of <code class="constant">GL_DRAW_BUFFER0</code> is <code class="constant">GL_BACK</code> if there
                        are back buffers, otherwise it is <code class="constant">GL_FRONT</code>.  The
                        initial values of draw buffers for all other output colors is <code class="constant">GL_NONE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DRAW_FRAMEBUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the name of the framebuffer object currently bound to the <code class="constant">GL_DRAW_FRAMEBUFFER</code> target.
                        If the default framebuffer is bound, this value will be zero. The initial value is zero.
                        See <a class="citerefentry" href="glBindFramebuffer"><span class="citerefentry"><span class="refentrytitle">glBindFramebuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_READ_FRAMEBUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the name of the framebuffer object currently bound to the <code class="constant">GL_READ_FRAMEBUFFER</code> target.
                        If the default framebuffer is bound, this value will be zero. The initial value is zero.
                        See <a class="citerefentry" href="glBindFramebuffer"><span class="citerefentry"><span class="refentrytitle">glBindFramebuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_ELEMENT_ARRAY_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_ELEMENT_ARRAY_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_FRAGMENT_SHADER_DERIVATIVE_HINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating the mode of the derivative accuracy hint
                        for fragment shaders. The initial value
                        is <code class="constant">GL_DONT_CARE</code>.
                        See <a class="citerefentry" href="glHint"><span class="citerefentry"><span class="refentrytitle">glHint</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_IMPLEMENTATION_COLOR_READ_FORMAT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single GLenum value indicating
                        the implementation's preferred pixel data format.
                        See <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_IMPLEMENTATION_COLOR_READ_TYPE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single GLenum value indicating
                        the implementation's preferred pixel data type.
                        See <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LINE_SMOOTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether antialiasing of
                        lines is enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LINE_SMOOTH_HINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating the mode of the line antialiasing
                        hint. The initial value is <code class="constant">GL_DONT_CARE</code>.
                        See <a class="citerefentry" href="glHint"><span class="citerefentry"><span class="refentrytitle">glHint</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LINE_WIDTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the line width as specified with <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>. The initial value is
                        1.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LAYER_PROVOKING_VERTEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the implementation dependent specifc vertex of a primitive that is used to select the rendering layer.
                        If the value returned is equivalent to <code class="constant">GL_PROVOKING_VERTEX</code>, then the vertex
                        selection follows the convention specified by
                        <a class="citerefentry" href="glProvokingVertex"><span class="citerefentry"><span class="refentrytitle">glProvokingVertex</span></span></a>.
                        If the value returned is equivalent to <code class="constant">GL_FIRST_VERTEX_CONVENTION</code>, then the
                        selection is always taken from the first vertex in the primitive.
                        If the value returned is equivalent to <code class="constant">GL_LAST_VERTEX_CONVENTION</code>, then the
                        selection is always taken from the last vertex in the primitive.
                        If the value returned is equivalent to <code class="constant">GL_UNDEFINED_VERTEX</code>, then the
                        selection is not guaranteed to be taken from any specific vertex in the primitive.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LOGIC_OP_MODE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating the selected logic operation
                        mode. The initial value is <code class="constant">GL_COPY</code>.
                        See <a class="citerefentry" href="glLogicOp"><span class="citerefentry"><span class="refentrytitle">glLogicOp</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAJOR_VERSION</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the major version number of the OpenGL API supported by the current context.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_3D_TEXTURE_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a rough estimate of the largest 3D texture that the GL can handle.
                        The value must be at least 64.
                        Use <code class="constant">GL_PROXY_TEXTURE_3D</code> to determine if a texture is too large.
                        See <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_ARRAY_TEXTURE_LAYERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value indicates the maximum number of layers allowed in an array texture, and must be at least 256.
                        See <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_CLIP_DISTANCES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of application-defined clipping distances. The value must be at least 8.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COLOR_TEXTURE_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of samples in a color multisample texture.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to all active shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of words for fragment shader uniform variables in all uniform
                        blocks (including default). The value must be at least 1.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of words for geometry shader uniform variables in all uniform
                        blocks (including default). The value must be at least 1.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the vertex shader and the fragment processor combined.
                        If both the vertex shader and the fragment processing stage access the same texture image
                        unit, then that counts as using two texture image units against this limit.
                        The value must be at least 48.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per program.  The value must be at least 70.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of words for vertex shader uniform variables in all uniform
                        blocks (including default). The value must be at least 1.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_CUBE_MAP_TEXTURE_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value gives a rough estimate of the largest cube-map texture that
                        the GL can handle. The value must be at least 1024.
                        Use <code class="constant">GL_PROXY_TEXTURE_CUBE_MAP</code>
                        to determine if a texture is too large.
                        See <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_DEPTH_TEXTURE_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of samples in a multisample depth or depth-stencil texture.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_DRAW_BUFFERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum number
                        of simultaneous outputs that may be written in a fragment shader.
                        The value must be at least 8.
                        See <a class="citerefentry" href="glDrawBuffers"><span class="citerefentry"><span class="refentrytitle">glDrawBuffers</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_DUAL_SOURCE_DRAW_BUFFERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum number
                        of active draw buffers when using dual-source  blending. The value must be at least 1.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and
                        <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_ELEMENTS_INDICES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the recommended maximum number of vertex array indices.
                        See <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_ELEMENTS_VERTICES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the recommended maximum number of vertex array vertices.
                        See <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to fragment shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a fragment shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_INPUT_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of components of the inputs read by the fragment shader, which must be at least 128.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual floating-point, integer, or boolean values that can be held
                        in uniform variable storage for a fragment shader. The value must be at least 1024.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_UNIFORM_VECTORS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual 4-vectors of floating-point, integer, or boolean values
                        that can be held
                        in uniform variable storage for a fragment shader. The value is equal to the value of
                        <code class="constant">GL_MAX_FRAGMENT_UNIFORM_COMPONENTS</code> divided by 4 and must be at least 256.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per fragment shader.  The value must be at least 12.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAMEBUFFER_WIDTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum width for a framebuffer that has no attachments, which must be at least 16384.
                        See <a class="citerefentry" href="glFramebufferParameter"><span class="citerefentry"><span class="refentrytitle">glFramebufferParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAMEBUFFER_HEIGHT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum height for a framebuffer that has no attachments, which must be at least 16384.
                        See <a class="citerefentry" href="glFramebufferParameter"><span class="citerefentry"><span class="refentrytitle">glFramebufferParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAMEBUFFER_LAYERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of layers for a framebuffer that has no attachments, which must be at least 2048.
                        See <a class="citerefentry" href="glFramebufferParameter"><span class="citerefentry"><span class="refentrytitle">glFramebufferParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAMEBUFFER_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum samples in a framebuffer that has no attachments, which must be at least 4.
                        See <a class="citerefentry" href="glFramebufferParameter"><span class="citerefentry"><span class="refentrytitle">glFramebufferParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to geometry shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a geometry shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_INPUT_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of components of inputs read by a geometry shader, which must be at least 64.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_OUTPUT_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of components of outputs written by a geometry shader, which must be at least 128.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the geometry shader. The value must be at least 16.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per geometry shader.  The value must be at least 12.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual floating-point, integer, or boolean values that can be held
                        in uniform variable storage for a geometry shader. The value must be at least 1024.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_INTEGER_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of samples supported in integer format multisample buffers.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MIN_MAP_BUFFER_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the minimum alignment in basic machine units of pointers returned from<a class="citerefentry" href="glMapBuffer"><span class="citerefentry"><span class="refentrytitle">glMapBuffer</span></span></a>
                        and <a class="citerefentry" href="glMapBufferRange"><span class="citerefentry"><span class="refentrytitle">glMapBufferRange</span></span></a>. This value must be a power of two and must
                        be at least 64.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_LABEL_LENGTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum length of a label that may be assigned to an object.
                        See <a class="citerefentry" href="glObjectLabel"><span class="citerefentry"><span class="refentrytitle">glObjectLabel</span></span></a> and
                        <a class="citerefentry" href="glObjectPtrLabel"><span class="citerefentry"><span class="refentrytitle">glObjectPtrLabel</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_PROGRAM_TEXEL_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum texel offset allowed in a texture lookup, which must be at least 7.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MIN_PROGRAM_TEXEL_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the minimum texel offset allowed in a texture lookup, which must be at most -8.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_RECTANGLE_TEXTURE_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value gives a rough estimate of the largest rectangular texture that
                        the GL can handle. The value must be at least 1024.
                        Use <code class="constant">GL_PROXY_TEXTURE_RECTANGLE</code>
                        to determine if a texture is too large.
                        See <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_RENDERBUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value indicates the maximum supported size for renderbuffers.
                        See <a class="citerefentry" href="glFramebufferRenderbuffer"><span class="citerefentry"><span class="refentrytitle">glFramebufferRenderbuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_SAMPLE_MASK_WORDS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of sample mask words.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_SERVER_WAIT_TIMEOUT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a> timeout interval.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of shader storage buffer binding points on the context, which must be at least 8.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to tessellation control shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to tessellation evaluation shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a tessellation control shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a tessellation evaluation shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TEXTURE_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value gives the maximum number of texels allowed in the texel array of a texture buffer object.
                        Value must be at least 65536.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the fragment shader.
                        The value must be at least 16.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TEXTURE_LOD_BIAS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum, absolute value of the texture level-of-detail bias.  The
                        value must be at least 2.0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TEXTURE_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value gives a rough estimate of the largest texture that
                        the GL can handle. The value must be at least 1024.
                        Use a proxy texture target such as <code class="constant">GL_PROXY_TEXTURE_1D</code> or <code class="constant">GL_PROXY_TEXTURE_2D</code>
                        to determine if a texture is too large.
                        See <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a> and <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_UNIFORM_BUFFER_BINDINGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform buffer binding points on the context, which must be at least 36.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_UNIFORM_BLOCK_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum size in basic machine units of a uniform block, which must be at least 16384.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_UNIFORM_LOCATIONS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of explicitly assignable uniform locations, which must be at least 1024.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VARYING_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number components for varying variables, which must be at least 60.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VARYING_VECTORS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number 4-vectors for varying variables, which is equal to the value of
                        <code class="constant">GL_MAX_VARYING_COMPONENTS</code> and must be at least 15.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VARYING_FLOATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of interpolators available for processing varying variables used by
                        vertex and fragment shaders. This value represents the number of individual floating-point
                        values that can be interpolated; varying variables declared as vectors, matrices, and arrays
                        will all consume multiple interpolators. The value must be at least 32.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to vertex shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_ATTRIBS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of 4-component generic vertex attributes accessible to a vertex shader.
                        The value must be at least 16.
                        See <a class="citerefentry" href="glVertexAttrib"><span class="citerefentry"><span class="refentrytitle">glVertexAttrib</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a vertex shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the vertex shader. The value may be at least 16.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual floating-point, integer, or boolean values that can be held
                        in uniform variable storage for a vertex shader. The value must be at least 1024.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_UNIFORM_VECTORS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of 4-vectors that may be held in uniform variable storage for the vertex
                        shader. The value of <code class="constant">GL_MAX_VERTEX_UNIFORM_VECTORS</code> is equal to the
                        value of <code class="constant">GL_MAX_VERTEX_UNIFORM_COMPONENTS</code> and must be at least
                        256.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_OUTPUT_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of components of output written by a vertex shader, which must be at least 64.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per vertex shader.  The value must be at least 12.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VIEWPORT_DIMS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns two values:
                        the maximum supported width and height of the viewport.
                        These must be at least as large as the visible dimensions of the display
                        being rendered to.
                        See <a class="citerefentry" href="glViewport"><span class="citerefentry"><span class="refentrytitle">glViewport</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VIEWPORTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum number
                        of simultaneous viewports that are supported.
                        The value must be at least 16.
                        See <a class="citerefentry" href="glViewportIndexed"><span class="citerefentry"><span class="refentrytitle">glViewportIndexed</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MINOR_VERSION</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the minor version number of the OpenGL API supported by the current context.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_NUM_COMPRESSED_TEXTURE_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value indicating the number of available
                        compressed texture formats.  The minimum value is 4.
                        See <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_NUM_EXTENSIONS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of extensions supported by the GL implementation for the current context.
                        See <a class="citerefentry" href="glGetString"><span class="citerefentry"><span class="refentrytitle">glGetString</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_NUM_PROGRAM_BINARY_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of program binary formats supported by the implementation.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_NUM_SHADER_BINARY_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of binary shader formats supported by the implementation. If this value is
                        greater than zero, then the implementation supports loading binary shaders. If it is
                        zero, then the loading of binary shaders by the implementation is not supported.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the byte alignment used for writing pixel data to memory. The initial
                        value is 4.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_IMAGE_HEIGHT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the image height used for writing pixel data to memory.  The initial
                        value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_LSB_FIRST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether single-bit
                        pixels being written to memory are written first to the least significant
                        bit of each unsigned byte. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_ROW_LENGTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the row length used for writing pixel data to memory. The initial value is
                        0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_SKIP_IMAGES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of pixel images skipped before the first pixel is written
                        into memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_SKIP_PIXELS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of pixel locations skipped before the first pixel is written
                        into memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_SKIP_ROWS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of rows of pixel locations skipped before the first pixel is written
                        into memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_SWAP_BYTES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether the bytes of
                        two-byte and four-byte pixel indices and components are swapped before being
                        written to memory. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PIXEL_PACK_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_PIXEL_PACK_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_PIXEL_UNPACK_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the point size threshold for determining the point size.
                        See <a class="citerefentry" href="glPointParameter"><span class="citerefentry"><span class="refentrytitle">glPointParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PRIMITIVE_RESTART_INDEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the current primitive restart index. The initial value is 0.
                        See <a class="citerefentry" href="glPrimitiveRestartIndex"><span class="citerefentry"><span class="refentrytitle">glPrimitiveRestartIndex</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROGRAM_BINARY_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> an array of <code class="constant">GL_NUM_PROGRAM_BINARY_FORMATS</code> values,
                        indicating the proram binary formats supported by the implementation.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROGRAM_PIPELINE_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> a single value, the name of the currently bound program pipeline
                        object, or zero if no program pipeline object is bound.
                        See <a class="citerefentry" href="glBindProgramPipeline"><span class="citerefentry"><span class="refentrytitle">glBindProgramPipeline</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROGRAM_POINT_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether vertex
                        program point size mode is enabled. If enabled, then the
                        point size is taken from the shader built-in <code class="code">gl_PointSize</code>. If disabled,
                        then the point size is taken from the point state as specified
                        by <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>.
                        The initial value is <code class="constant">GL_FALSE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROVOKING_VERTEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the currently selected provoking vertex convention. The initial value is <code class="constant">GL_LAST_VERTEX_CONVENTION</code>.
                        See <a class="citerefentry" href="glProvokingVertex"><span class="citerefentry"><span class="refentrytitle">glProvokingVertex</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the point size as specified by <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>.
                        The initial value is 1.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SIZE_GRANULARITY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the size difference between adjacent supported sizes for antialiased points.
                        See <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SIZE_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns two values:
                        the smallest and largest supported sizes for antialiased
                        points. The smallest size must be at most 1, and the largest size must
                        be at least 1.
                        See <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_FACTOR</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the scaling factor used to determine the variable offset that is added
                        to the depth value of each fragment generated when a polygon is
                        rasterized. The initial value is 0.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        This value is multiplied by an implementation-specific value and then
                        added to the depth value of each fragment
                        generated when a polygon is rasterized. The initial value is 0.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_FILL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether polygon offset
                        is enabled for polygons in fill mode. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_LINE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether polygon offset
                        is enabled for polygons in line mode. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_POINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether polygon offset
                        is enabled for polygons in point mode. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_SMOOTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether antialiasing of
                        polygons is enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPolygonMode"><span class="citerefentry"><span class="refentrytitle">glPolygonMode</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_SMOOTH_HINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating the mode of the polygon antialiasing
                        hint. The initial value is <code class="constant">GL_DONT_CARE</code>.
                        See <a class="citerefentry" href="glHint"><span class="citerefentry"><span class="refentrytitle">glHint</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_READ_BUFFER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating which color buffer is selected for
                        reading. The initial value is <code class="constant">GL_BACK</code> if there is a back buffer,
                        otherwise it is <code class="constant">GL_FRONT</code>.
                        See
                        <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_RENDERBUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the renderbuffer object
                        currently bound to the target <code class="constant">GL_RENDERBUFFER</code>. If no renderbuffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindRenderbuffer"><span class="citerefentry"><span class="refentrytitle">glBindRenderbuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_BUFFERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value indicating the number of sample buffers
                        associated with the framebuffer.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_COVERAGE_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single positive floating-point value indicating the
                        current sample coverage value.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_COVERAGE_INVERT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating if the temporary
                        coverage value should be inverted.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_MASK_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns one value, the 32-bit sub-word of the sample mask
												that specifies which samples to update. The index must be less than <code class="constant">GL_MAX_SAMPLE_MASK_WORDS</code>.
												The initial value is all 1's.
                        See <a class="citerefentry" href="glSampleMaski"><span class="citerefentry"><span class="refentrytitle">glSampleMaski</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the sampler object
                        currently bound to the active texture unit.  The initial value is 0.
                        See <a class="citerefentry" href="glBindSampler"><span class="citerefentry"><span class="refentrytitle">glBindSampler</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value indicating the coverage mask size.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SCISSOR_BOX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns four values:
                        the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates of the scissor box,
                        followed by its width and height.
                        Initially the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates are both 0 and the
                        width and height are set to the size of the window.
                        See <a class="citerefentry" href="glScissor"><span class="citerefentry"><span class="refentrytitle">glScissor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SCISSOR_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether scissoring is
                        enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glScissor"><span class="citerefentry"><span class="refentrytitle">glScissor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_COMPILER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether an online shader
                        compiler is present in the implementation. All desktop OpenGL implementations must support
                        online shader compilations, and therefore the value of <code class="constant">GL_SHADER_COMPILER</code>
                        will always be <code class="constant">GL_TRUE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_STORAGE_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with non-indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegerv</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_SHADER_STORAGE_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        bound to the indexed shader storage buffer binding points. The initial value is 0 for all targets.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>, <a class="citerefentry" href="glBindBufferBase"><span class="citerefentry"><span class="refentrytitle">glBindBufferBase</span></span></a>, and
                        <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the minimum required alignment
                        for shader storage buffer sizes and offset.  The initial value is 1.
                        See <a class="citerefentry" href="glShaderStorateBlockBinding"><span class="citerefentry"><span class="refentrytitle">glShaderStorateBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_STORAGE_BUFFER_START</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the start offset of the binding range for each
                        indexed shader storage buffer binding. The initial value is 0 for all bindings.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_STORAGE_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the size of the binding range for each
                        indexed shader storage buffer binding. The initial value is 0 for all bindings.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SMOOTH_LINE_WIDTH_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a pair of values indicating the range of
                        widths supported for smooth (antialiased) lines. See <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SMOOTH_LINE_WIDTH_GRANULARITY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value indicating the level of
                        quantization applied to smooth line width parameters.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_FAIL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken for back-facing polygons when the stencil
                        test fails. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_FUNC</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what function is used for back-facing polygons to compare the
                        stencil reference value with the stencil buffer value. The initial value
                        is <code class="constant">GL_ALWAYS</code>.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_PASS_DEPTH_FAIL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken for back-facing polygons when the stencil
                        test passes,
                        but the depth test fails. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_PASS_DEPTH_PASS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken for back-facing polygons when the stencil
                        test passes and the depth test passes. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_REF</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the reference value that is compared with the contents of the stencil
                        buffer for back-facing polygons. The initial value is 0.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_VALUE_MASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the mask that is used for back-facing polygons to mask both the stencil reference value and the
                        stencil buffer value before they are compared. The initial value is all 1's.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_WRITEMASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the mask that controls writing of the stencil bitplanes for back-facing polygons. The initial value
                        is all 1's.
                        See <a class="citerefentry" href="glStencilMaskSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilMaskSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_CLEAR_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the index to which the stencil bitplanes are cleared. The initial value is
                        0.
                        See <a class="citerefentry" href="glClearStencil"><span class="citerefentry"><span class="refentrytitle">glClearStencil</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_FAIL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken when the stencil
                        test fails. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_FUNC</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what function is used to compare the
                        stencil reference value with the stencil buffer value. The initial value
                        is <code class="constant">GL_ALWAYS</code>.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_PASS_DEPTH_FAIL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken when the stencil
                        test passes,
                        but the depth test fails. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_PASS_DEPTH_PASS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken when the stencil
                        test passes and the depth test passes. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_REF</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the reference value that is compared with the contents of the stencil
                        buffer. The initial value is 0.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether stencil testing
                        of fragments is enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a> and <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_VALUE_MASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the mask that is used to mask both the stencil reference value and the
                        stencil buffer value before they are compared. The initial value is all 1's.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_WRITEMASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the mask that controls writing of the stencil bitplanes. The initial value
                        is all 1's.
                        See <a class="citerefentry" href="glStencilMask"><span class="citerefentry"><span class="refentrytitle">glStencilMask</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilMaskSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilMaskSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STEREO</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether stereo buffers
                        (left and right) are supported.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SUBPIXEL_BITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        an estimate of the number of bits of subpixel resolution that are used to
                        position rasterized geometry in window coordinates. The value must be at least 4.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_1D</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_1D</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_1D_ARRAY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_1D_ARRAY</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_2D</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_2D</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_2D_ARRAY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_2D_ARRAY</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_2D_MULTISAMPLE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_3D</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_3D</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_BUFFER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_BUFFER</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_CUBE_MAP</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_CUBE_MAP</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_RECTANGLE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_RECTANGLE</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_COMPRESSION_HINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value indicating the mode of the texture
                        compression hint.  The initial value is <code class="constant">GL_DONT_CARE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the minimum required alignment
                        for texture buffer sizes and offset.  The initial value is 1.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TIMESTAMP</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the 64-bit value of the current
                        GL time.
                        See <a class="citerefentry" href="glQueryCounter"><span class="citerefentry"><span class="refentrytitle">glQueryCounter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with non-indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegerv</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        bound to the indexed transform feedback attribute stream. The initial value is 0 for all targets.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>, <a class="citerefentry" href="glBindBufferBase"><span class="citerefentry"><span class="refentrytitle">glBindBufferBase</span></span></a>, and
                        <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER_START</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the start offset of the binding range for each
                        transform feedback attribute stream. The initial value is 0 for all streams.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the size of the binding range for each
                        transform feedback attribute stream. The initial value is 0 for all streams.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNIFORM_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with non-indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegerv</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_UNIFORM_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        bound to the indexed uniform buffer binding point. The initial value is 0 for all targets.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>, <a class="citerefentry" href="glBindBufferBase"><span class="citerefentry"><span class="refentrytitle">glBindBufferBase</span></span></a>, and
                        <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the minimum required alignment
                        for uniform buffer sizes and offset.  The initial value is 1.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNIFORM_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the size of the binding range for each
                        indexed uniform buffer binding. The initial value is 0 for all bindings.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNIFORM_BUFFER_START</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the start offset of the binding range for each
                        indexed uniform buffer binding. The initial value is 0 for all bindings.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the byte alignment used for reading pixel data from memory. The initial
                        value is 4.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_IMAGE_HEIGHT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the image height used for reading pixel data from memory.  The initial
                        is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_LSB_FIRST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether single-bit
                        pixels being read from memory are read first from the least significant
                        bit of each unsigned byte. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_ROW_LENGTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the row length used for reading pixel data from memory. The initial value
                        is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_SKIP_IMAGES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of pixel images skipped before the first pixel is read
                        from memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_SKIP_PIXELS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of pixel locations skipped before the first pixel is read
                        from memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_SKIP_ROWS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of rows of pixel locations skipped before the first pixel is read
                        from memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_SWAP_BYTES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether the bytes of
                        two-byte and four-byte pixel indices and components are swapped after being
                        read from memory. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VERTEX_ARRAY_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the vertex array object
                        currently bound to the context. If no vertex array object
                        is bound to the context, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindVertexArray"><span class="citerefentry"><span class="refentrytitle">glBindVertexArray</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VERTEX_BINDING_DIVISOR</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed forms. <em class="parameter"><code>data</code></em> returns a single integer value representing the instance step
                        divisor of the first element in the bound buffer's data store for vertex attribute bound to <em class="parameter"><code>index</code></em>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VERTEX_BINDING_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed forms. <em class="parameter"><code>data</code></em> returns a single integer value representing the byte offset
                        of the first element in the bound buffer's data store for vertex attribute bound to <em class="parameter"><code>index</code></em>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VERTEX_BINDING_STRIDE</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed forms. <em class="parameter"><code>data</code></em> returns a single integer value representing the byte offset
                        between the start of each element in the bound buffer's data store for vertex attribute bound to <em class="parameter"><code>index</code></em>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value containing the maximum offset that may be added to a vertex binding
                        offset.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_ATTRIB_BINDINGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value containing the maximum number of vertex buffers that may be bound.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VIEWPORT</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with non-indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegerv</code>),
                        <em class="parameter"><code>data</code></em> returns four values:
                        the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates of the viewport, followed by its width and height.
                        Initially the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates are both set to 0,
                        and the width and height are set to the width and height of the window into
                        which the GL will do its rendering.
                        See <a class="citerefentry" href="glViewport"><span class="citerefentry"><span class="refentrytitle">glViewport</span></span></a>.
                    </p>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns four values:
                        the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates of the indexed viewport, followed by its width and height.
                        Initially the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates are both set to 0,
                        and the width and height are set to the width and height of the window into
                        which the GL will do its rendering.
                        See <a class="citerefentry" href="glViewportIndexedf"><span class="citerefentry"><span class="refentrytitle">glViewportIndexedf</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VIEWPORT_BOUNDS_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns two values, the minimum and maximum viewport bounds range.
                        The minimum range should be at least [-32768, 32767].
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VIEWPORT_INDEX_PROVOKING_VERTEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the implementation dependent specifc vertex of a primitive that is used to select the viewport index.
                        If the value returned is equivalent to <code class="constant">GL_PROVOKING_VERTEX</code>, then the vertex
                        selection follows the convention specified by
                        <a class="citerefentry" href="glProvokingVertex"><span class="citerefentry"><span class="refentrytitle">glProvokingVertex</span></span></a>.
                        If the value returned is equivalent to <code class="constant">GL_FIRST_VERTEX_CONVENTION</code>, then the
                        selection is always taken from the first vertex in the primitive.
                        If the value returned is equivalent to <code class="constant">GL_LAST_VERTEX_CONVENTION</code>, then the
                        selection is always taken from the last vertex in the primitive.
                        If the value returned is equivalent to <code class="constant">GL_UNDEFINED_VERTEX</code>, then the
                        selection is not guaranteed to be taken from any specific vertex in the primitive.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VIEWPORT_SUBPIXEL_BITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the number of bits of sub-pixel precision which the GL
                        uses to interpret the floating point viewport bounds. The minimum value is 0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_ELEMENT_INDEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum index that may be specified during the
                        transfer of generic vertex attributes to the GL.
                    </p>
            </dd>
          </dl>
        </div>
        <p>
            Many of the boolean parameters can also be queried more easily using
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The following parameters return the associated value for the active texture unit:
            <code class="constant">GL_TEXTURE_1D</code>, <code class="constant">GL_TEXTURE_BINDING_1D</code>,
            <code class="constant">GL_TEXTURE_2D</code>, <code class="constant">GL_TEXTURE_BINDING_2D</code>,
            <code class="constant">GL_TEXTURE_3D</code> and <code class="constant">GL_TEXTURE_BINDING_3D</code>.
        </p>
        <p>
            <code class="constant">GL_MAX_VIEWPORTS</code>, <code class="constant">GL_VIEWPORT_SUBPIXEL_BITS</code>,
            <code class="constant">GL_VIEWPORT_BOUNDS_RANGE</code>, <code class="constant">GL_LAYER_PROVOKING_VERTEX</code>,
            and <code class="constant">GL_VIEWPORT_INDEX_PROVOKING_VERTEX</code>
            are available only if the GL version is 4.1 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_VERTEX_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_GEOMETRY_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_FRAMGENT_ATOMIC_COUNTERS</code>, and
            <code class="constant">GL_MIN_MAP_BUFFER_ALIGNMENT</code> are accepted by <em class="parameter"><code>pname</code></em>
            only if the GL version is 4.2 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_ELEMENT_INDEX</code> is accepted by <em class="parameter"><code>pname</code></em> only
            if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_COMPUTE_UNIFORM_BLOCKS</code>, <code class="constant">GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS</code>,
            <code class="constant">GL_MAX_COMPUTE_UNIFORM_COMPONENTS</code>, <code class="constant">GL_MAX_COMPUTE_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS</code>, <code class="constant">GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS</code>,
            <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS</code>, <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_COUNT</code>, and
            <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_SIZE</code> and <code class="constant">GL_DISPATCH_INDIRECT_BUFFER_BINDING</code> are available only if the GL version
            is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_DEBUG_GROUP_STACK_DEPTH</code>, <code class="constant">GL_DEBUG_GROUP_STACK_DEPTH</code> and <code class="constant">GL_MAX_LABEL_LENGTH</code> are accepted only if
            the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_UNIFORM_LOCATIONS</code> is accepted only if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_FRAMEBUFFER_WIDTH</code>, <code class="constant">GL_MAX_FRAMEBUFFER_HEIGHT</code>, <code class="constant">GL_MAX_FRAMEBUFFER_LAYERS</code>,
            and <code class="constant">GL_MAX_FRAMEBUFFER_SAMPLES</code> are available only if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS</code>, <code class="constant">GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS</code>,
            <code class="constant">GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS</code>, <code class="constant">GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS</code>,
            <code class="constant">GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS</code>, and <code class="constant">GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS</code> are available
            only if the GL version is 4.3 or higher.
        </p>
        <p>
            <code class="constant">GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT</code> is available only if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_VERTEX_BINDING_DIVISOR</code>, <code class="constant">GL_VERTEX_BINDING_OFFSET</code>, <code class="constant">GL_VERTEX_BINDING_STRIDE</code>,
            <code class="constant">GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET</code> and <code class="constant">GL_MAX_VERTEX_ATTRIB_BINDINGS</code> are available only if
            the GL version is 4.3 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>pname</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated on any of <code class="function">glGetBooleani_v</code>,
            <code class="function">glGetIntegeri_v</code>, or <code class="function">glGetInteger64i_v</code> if
            <em class="parameter"><code>index</code></em> is outside of the valid range for the indexed state <em class="parameter"><code>target</code></em>.
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
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glGetBooleani_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetBooleanv</code>
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
                  <code class="function">glGetDoublei_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glGetDoublev</code>
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
                  <code class="function">glGetFloati_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glGetFloatv</code>
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
                  <code class="function">glGetInteger64i_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetInteger64v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetIntegeri_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetIntegerv</code>
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
            <a class="citerefentry" href="glGetActiveUniform"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniform</span></span></a>,
            <a class="citerefentry" href="glGetAttachedShaders"><span class="citerefentry"><span class="refentrytitle">glGetAttachedShaders</span></span></a>,
            <a class="citerefentry" href="glGetAttribLocation"><span class="citerefentry"><span class="refentrytitle">glGetAttribLocation</span></span></a>,
            <a class="citerefentry" href="glGetBufferParameter"><span class="citerefentry"><span class="refentrytitle">glGetBufferParameter</span></span></a>,
            <a class="citerefentry" href="glGetBufferPointerv"><span class="citerefentry"><span class="refentrytitle">glGetBufferPointerv</span></span></a>,
            <a class="citerefentry" href="glGetBufferSubData"><span class="citerefentry"><span class="refentrytitle">glGetBufferSubData</span></span></a>,
            <a class="citerefentry" href="glGetCompressedTexImage"><span class="citerefentry"><span class="refentrytitle">glGetCompressedTexImage</span></span></a>,
            <a class="citerefentry" href="glGetError"><span class="citerefentry"><span class="refentrytitle">glGetError</span></span></a>,
            <a class="citerefentry" href="glGetProgram"><span class="citerefentry"><span class="refentrytitle">glGetProgram</span></span></a>,
            <a class="citerefentry" href="glGetProgramInfoLog"><span class="citerefentry"><span class="refentrytitle">glGetProgramInfoLog</span></span></a>,
            <a class="citerefentry" href="glGetQueryiv"><span class="citerefentry"><span class="refentrytitle">glGetQueryiv</span></span></a>,
            <a class="citerefentry" href="glGetQueryObject"><span class="citerefentry"><span class="refentrytitle">glGetQueryObject</span></span></a>,
            <a class="citerefentry" href="glGetShader"><span class="citerefentry"><span class="refentrytitle">glGetShader</span></span></a>,
            <a class="citerefentry" href="glGetShaderInfoLog"><span class="citerefentry"><span class="refentrytitle">glGetShaderInfoLog</span></span></a>,
            <a class="citerefentry" href="glGetShaderSource"><span class="citerefentry"><span class="refentrytitle">glGetShaderSource</span></span></a>,
            <a class="citerefentry" href="glGetString"><span class="citerefentry"><span class="refentrytitle">glGetString</span></span></a>,
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>,
            <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>,
            <a class="citerefentry" href="glGetTexParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexParameter</span></span></a>,
            <a class="citerefentry" href="glGetUniform"><span class="citerefentry"><span class="refentrytitle">glGetUniform</span></span></a>,
            <a class="citerefentry" href="glGetUniformLocation"><span class="citerefentry"><span class="refentrytitle">glGetUniformLocation</span></span></a>,
            <a class="citerefentry" href="glGetVertexAttrib"><span class="citerefentry"><span class="refentrytitle">glGetVertexAttrib</span></span></a>,
            <a class="citerefentry" href="glGetVertexAttribPointerv"><span class="citerefentry"><span class="refentrytitle">glGetVertexAttribPointerv</span></span></a>,
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGet.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetInteger64v glad_glGetInteger64v
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
GLAPI PFNGLGETSYNCIVPROC glad_glGetSynciv;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetSync'>OpenGL 4</a><br /><a  href='../gl3/glGetSync'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glGetSync</h1>
    <div class="refentry" id="glGetSync">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetSynciv — query the properties of a sync object</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetSynciv</strong>(</code>
              </td>
              <td>GLsync <var class="pdparam">sync</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">bufSize</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei *<var class="pdparam">length</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint *<var class="pdparam">values</var><code>)</code>;</td>
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
                  <code>sync</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the sync object whose properties to query.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pname</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the parameter whose value to retrieve from the sync object specified in <em class="parameter"><code>sync</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>bufSize</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the size of the buffer whose address is given in <em class="parameter"><code>values</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>length</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of an variable to receive the number of integers placed in <em class="parameter"><code>values</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>values</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of an array to receive the values of the queried parameter.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetSynciv</code> retrieves properties of a sync object. <em class="parameter"><code>sync</code></em> specifies the name of the sync
            object whose properties to retrieve.
        </p>
        <p>
            On success, <code class="function">glGetSynciv</code> replaces up to <em class="parameter"><code>bufSize</code></em> integers in <em class="parameter"><code>values</code></em> with the
            corresponding property values of the object being queried.  The actual number of integers replaced is returned in the variable whose address is
            specified in <em class="parameter"><code>length</code></em>. If <em class="parameter"><code>length</code></em> is <code class="code">NULL</code>, no length is returned.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_OBJECT_TYPE</code>, a single value representing the specific type of the sync object is
            placed in <em class="parameter"><code>values</code></em>. The only type supported is <code class="constant">GL_SYNC_FENCE</code>.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_SYNC_STATUS</code>, a single value representing the status of the sync object
            (<code class="constant">GL_SIGNALED</code> or <code class="constant">GL_UNSIGNALED</code>) is placed in <em class="parameter"><code>values</code></em>.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_SYNC_CONDITION</code>, a single value representing the condition of the sync object
            is placed in <em class="parameter"><code>values</code></em>. The only condition supported is <code class="constant">GL_SYNC_GPU_COMMANDS_COMPLETE</code>.
        </p>
        <p>
            If <em class="parameter"><code>pname</code></em> is <code class="constant">GL_SYNC_FLAGS</code>, a single value representing the flags with which the sync object
            was created is placed in <em class="parameter"><code>values</code></em>. No flags are currently supported<a href="#ftn.idp140880" class="footnote"><sup class="footnote" id="idp140880">[1]</sup></a>.
        </p>
        <p>
            If an error occurs, nothing will be written to <em class="parameter"><code>values</code></em> or <em class="parameter"><code>length</code></em>.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>sync</code></em> is not the name of a sync object.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>pname</code></em> is not one of the accepted tokens.
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
                  <code class="function">glGetSynciv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glFenceSync"><span class="citerefentry"><span class="refentrytitle">glFenceSync</span></span></a>,
            <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a>,
            <a class="citerefentry" href="glClientWaitSync"><span class="citerefentry"><span class="refentrytitle">glClientWaitSync</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
      <div class="footnotes">
        <br/>
        <hr class="footnote-hr"/>
        <div id="ftn.idp140880" class="footnote">
          <p><a href="#idp140880" class="para"><sup class="para">[1] </sup></a><em class="parameter"><code>flags</code></em> is
            expected to be used in future extensions to the sync objects.</p>
        </div>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetSync.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetSynciv glad_glGetSynciv
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64 *data);
GLAPI PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGet'>OpenGL 4</a><br /><a  href='../gl3/glGet'>OpenGL 3</a><br /><a  href='../gl2/glGet'>OpenGL 2</a><br /><a  href='../es3/glGet'>OpenGL ES 3</a><br /><a  href='../es2/glGet'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glGet</h1>
    <div class="refentry" id="glGet">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGet — return the value or values of a selected parameter</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetBooleanv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLboolean * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetDoublev</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLdouble * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetFloatv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetIntegerv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetInteger64v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint64 * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetBooleani_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLboolean * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetIntegeri_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetFloati_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetDoublei_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLdouble * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetInteger64i_v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint64 * <var class="pdparam">data</var><code>)</code>;</td>
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
                    Specifies the parameter value to be returned
                    for non-indexed versions of <code class="function">glGet</code>.
                    The symbolic constants in the list below are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the parameter value to be returned
                    for indexed versions of <code class="function">glGet</code>.
                    The symbolic constants in the list below are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>index</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the index of the particular element being queried.
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
                    Returns the value or values of the specified parameter.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            These commands return values for simple state variables in GL.
            <em class="parameter"><code>pname</code></em> is a symbolic constant indicating the state variable to be returned,
            and <em class="parameter"><code>data</code></em> is a pointer to an array of the indicated type in
            which to place the returned data.
        </p>
        <p>
            Type conversion is performed if <em class="parameter"><code>data</code></em> has a different type than
            the state variable value being requested.
            If <code class="function">glGetBooleanv</code> is called,
            a floating-point (or integer) value is converted to <code class="constant">GL_FALSE</code> if
            and only if it is 0.0 (or 0).
            Otherwise,
            it is converted to <code class="constant">GL_TRUE</code>.
            If <code class="function">glGetIntegerv</code> is called, boolean values are returned as
            <code class="constant">GL_TRUE</code> or <code class="constant">GL_FALSE</code>, and most floating-point values are
            rounded to the nearest integer value. Floating-point colors and
            normals, however, are returned with a linear mapping that maps 1.0 to
            the most positive representable integer value
            and
            <math overflow="scroll">

                <mn>-1.0</mn>
            </math>
            to the most negative representable integer value.
            If <code class="function">glGetFloatv</code> or <code class="function">glGetDoublev</code> is called,
            boolean values are returned as <code class="constant">GL_TRUE</code> or <code class="constant">GL_FALSE</code>,
            and integer values are converted to floating-point values.
        </p>
        <p>
            The following symbolic constants are accepted by <em class="parameter"><code>pname</code></em>:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_ACTIVE_TEXTURE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value indicating the active multitexture unit.
                        The initial value is <code class="constant">GL_TEXTURE0</code>.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_ALIASED_LINE_WIDTH_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a pair of values indicating the range of
                        widths supported for aliased lines. See <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_ARRAY_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_ARRAY_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether blending is
                        enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_COLOR</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns four values,
                        the red, green, blue, and alpha values which are the components of
                        the blend color.
                        See <a class="citerefentry" href="glBlendColor"><span class="citerefentry"><span class="refentrytitle">glBlendColor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_DST_ALPHA</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant identifying the alpha destination blend
                        function. The initial value is <code class="constant">GL_ZERO</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_DST_RGB</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant identifying the RGB destination blend
                        function. The initial value is <code class="constant">GL_ZERO</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_EQUATION_RGB</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, a symbolic constant indicating whether
                        the RGB blend equation is <code class="constant">GL_FUNC_ADD</code>, <code class="constant">GL_FUNC_SUBTRACT</code>,
                        <code class="constant">GL_FUNC_REVERSE_SUBTRACT</code>, <code class="constant">GL_MIN</code> or <code class="constant">GL_MAX</code>.
                        See <a class="citerefentry" href="glBlendEquationSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendEquationSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_EQUATION_ALPHA</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, a symbolic constant indicating whether
                        the Alpha blend equation is <code class="constant">GL_FUNC_ADD</code>, <code class="constant">GL_FUNC_SUBTRACT</code>,
                        <code class="constant">GL_FUNC_REVERSE_SUBTRACT</code>, <code class="constant">GL_MIN</code> or <code class="constant">GL_MAX</code>.
                        See <a class="citerefentry" href="glBlendEquationSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendEquationSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_SRC_ALPHA</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant identifying the alpha source blend function. The initial
                        value is <code class="constant">GL_ONE</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND_SRC_RGB</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant identifying the RGB source blend function. The initial
                        value is <code class="constant">GL_ONE</code>.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COLOR_CLEAR_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns four values:
                        the red, green, blue, and alpha values used to clear the color buffers.
                        Integer values,
                        if requested,
                        are linearly mapped from the internal floating-point representation such
                        that 1.0 returns the most positive representable integer value,
                        and
                        <math overflow="scroll">

                            <mn>-1.0</mn>
                        </math>
                        returns the most negative representable integer
                        value. The initial value is (0, 0, 0, 0).
                        See <a class="citerefentry" href="glClearColor"><span class="citerefentry"><span class="refentrytitle">glClearColor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COLOR_LOGIC_OP</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether a fragment's
                        RGBA color values are merged into the framebuffer using a logical
                        operation. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glLogicOp"><span class="citerefentry"><span class="refentrytitle">glLogicOp</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COLOR_WRITEMASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns four boolean values:
                        the red, green, blue, and alpha write enables for the color
                        buffers. The initial value is (<code class="constant">GL_TRUE</code>, <code class="constant">GL_TRUE</code>,
                        <code class="constant">GL_TRUE</code>, <code class="constant">GL_TRUE</code>).
                        See <a class="citerefentry" href="glColorMask"><span class="citerefentry"><span class="refentrytitle">glColorMask</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COMPRESSED_TEXTURE_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a list of symbolic
                        constants of length <code class="constant">GL_NUM_COMPRESSED_TEXTURE_FORMATS</code>
                        indicating which compressed texture formats are available.
                        See <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a compute shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum total number of active shader storage blocks that may be accessed by all active shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per compute shader.  The value must be at least 14.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the compute shader. The value may be at least 16.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual floating-point, integer, or boolean values that can be held
                        in uniform variable storage for a compute shader. The value must be at least 1024.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to compute shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counter buffers that may be accessed by a compute shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of words for compute shader uniform variables in all uniform
                        blocks (including default). The value must be at least 1.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of invocations in a single local work group
                        (i.e., the product of the three dimensions) that may
                        be dispatched to a compute shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_COUNT</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed versions of <code class="function">glGet</code>.
                        <em class="parameter"><code>data</code></em> the maximum number of work
                        groups that may be dispatched to a compute shader. Indices
                        0, 1, and 2 correspond to the X, Y and Z dimensions, respectively.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed versions of <code class="function">glGet</code>.
                        <em class="parameter"><code>data</code></em> the maximum size of a work
                        groups that may be used during compilation of a compute shader. Indices
                        0, 1, and 2 correspond to the X, Y and Z dimensions, respectively.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DISPATCH_INDIRECT_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_DISPATCH_INDIRECT_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_DEBUG_GROUP_STACK_DEPTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum depth of the
                        debug message group stack.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEBUG_GROUP_STACK_DEPTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the current depth of the
                        debug message group stack.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_CONTEXT_FLAGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the flags with which the context was created (such as debugging functionality).
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_CULL_FACE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether polygon culling
                        is enabled. The initial value is <code class="constant">GL_BACK</code>.
                        See <a class="citerefentry" href="glCullFace"><span class="citerefentry"><span class="refentrytitle">glCullFace</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_CURRENT_PROGRAM</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the name of the program object that is currently active, or 0 if no program object is active.
                        See <a class="citerefentry" href="glUseProgram"><span class="citerefentry"><span class="refentrytitle">glUseProgram</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_CLEAR_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the value that is used to clear the depth buffer.
                        Integer values,
                        if requested,
                        are linearly mapped from the internal floating-point representation such
                        that 1.0 returns the most positive representable integer value,
                        and
                        <math overflow="scroll">

                            <mn>-1.0</mn>
                        </math>
                        returns the most negative representable integer
                        value. The initial value is 1.
                        See <a class="citerefentry" href="glClearDepth"><span class="citerefentry"><span class="refentrytitle">glClearDepth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_FUNC</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the symbolic constant that indicates the depth comparison
                        function. The initial value is <code class="constant">GL_LESS</code>.
                        See <a class="citerefentry" href="glDepthFunc"><span class="citerefentry"><span class="refentrytitle">glDepthFunc</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns two values:
                        the near and far mapping limits for the depth buffer.
                        Integer values,
                        if requested,
                        are linearly mapped from the internal floating-point representation such
                        that 1.0 returns the most positive representable integer value,
                        and
                        <math overflow="scroll">

                            <mn>-1.0</mn>
                        </math>
                        returns the most negative representable integer
                        value. The initial value is (0, 1).
                        See <a class="citerefentry" href="glDepthRange"><span class="citerefentry"><span class="refentrytitle">glDepthRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether depth testing
                        of fragments is enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glDepthFunc"><span class="citerefentry"><span class="refentrytitle">glDepthFunc</span></span></a> and <a class="citerefentry" href="glDepthRange"><span class="citerefentry"><span class="refentrytitle">glDepthRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_WRITEMASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating if the depth buffer
                        is enabled for writing. The initial value is <code class="constant">GL_TRUE</code>.
                        See <a class="citerefentry" href="glDepthMask"><span class="citerefentry"><span class="refentrytitle">glDepthMask</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DITHER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether dithering of
                        fragment colors and indices is enabled. The initial value is <code class="constant">GL_TRUE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DOUBLEBUFFER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether double buffering
                        is supported.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DRAW_BUFFER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating which buffers are being drawn to.
                        See <a class="citerefentry" href="glDrawBuffer"><span class="citerefentry"><span class="refentrytitle">glDrawBuffer</span></span></a>. The initial value is <code class="constant">GL_BACK</code> if there
                        are back buffers, otherwise it is <code class="constant">GL_FRONT</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DRAW_BUFFER</code>
                <span class="emphasis">
                  <em>i</em>
                </span>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating which buffers are being drawn to by the corresponding output color.
                        See <a class="citerefentry" href="glDrawBuffers"><span class="citerefentry"><span class="refentrytitle">glDrawBuffers</span></span></a>.
                        The initial value of <code class="constant">GL_DRAW_BUFFER0</code> is <code class="constant">GL_BACK</code> if there
                        are back buffers, otherwise it is <code class="constant">GL_FRONT</code>.  The
                        initial values of draw buffers for all other output colors is <code class="constant">GL_NONE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DRAW_FRAMEBUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the name of the framebuffer object currently bound to the <code class="constant">GL_DRAW_FRAMEBUFFER</code> target.
                        If the default framebuffer is bound, this value will be zero. The initial value is zero.
                        See <a class="citerefentry" href="glBindFramebuffer"><span class="citerefentry"><span class="refentrytitle">glBindFramebuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_READ_FRAMEBUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the name of the framebuffer object currently bound to the <code class="constant">GL_READ_FRAMEBUFFER</code> target.
                        If the default framebuffer is bound, this value will be zero. The initial value is zero.
                        See <a class="citerefentry" href="glBindFramebuffer"><span class="citerefentry"><span class="refentrytitle">glBindFramebuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_ELEMENT_ARRAY_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_ELEMENT_ARRAY_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_FRAGMENT_SHADER_DERIVATIVE_HINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating the mode of the derivative accuracy hint
                        for fragment shaders. The initial value
                        is <code class="constant">GL_DONT_CARE</code>.
                        See <a class="citerefentry" href="glHint"><span class="citerefentry"><span class="refentrytitle">glHint</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_IMPLEMENTATION_COLOR_READ_FORMAT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single GLenum value indicating
                        the implementation's preferred pixel data format.
                        See <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_IMPLEMENTATION_COLOR_READ_TYPE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single GLenum value indicating
                        the implementation's preferred pixel data type.
                        See <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LINE_SMOOTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether antialiasing of
                        lines is enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LINE_SMOOTH_HINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating the mode of the line antialiasing
                        hint. The initial value is <code class="constant">GL_DONT_CARE</code>.
                        See <a class="citerefentry" href="glHint"><span class="citerefentry"><span class="refentrytitle">glHint</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LINE_WIDTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the line width as specified with <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>. The initial value is
                        1.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LAYER_PROVOKING_VERTEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the implementation dependent specifc vertex of a primitive that is used to select the rendering layer.
                        If the value returned is equivalent to <code class="constant">GL_PROVOKING_VERTEX</code>, then the vertex
                        selection follows the convention specified by
                        <a class="citerefentry" href="glProvokingVertex"><span class="citerefentry"><span class="refentrytitle">glProvokingVertex</span></span></a>.
                        If the value returned is equivalent to <code class="constant">GL_FIRST_VERTEX_CONVENTION</code>, then the
                        selection is always taken from the first vertex in the primitive.
                        If the value returned is equivalent to <code class="constant">GL_LAST_VERTEX_CONVENTION</code>, then the
                        selection is always taken from the last vertex in the primitive.
                        If the value returned is equivalent to <code class="constant">GL_UNDEFINED_VERTEX</code>, then the
                        selection is not guaranteed to be taken from any specific vertex in the primitive.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LOGIC_OP_MODE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating the selected logic operation
                        mode. The initial value is <code class="constant">GL_COPY</code>.
                        See <a class="citerefentry" href="glLogicOp"><span class="citerefentry"><span class="refentrytitle">glLogicOp</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAJOR_VERSION</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the major version number of the OpenGL API supported by the current context.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_3D_TEXTURE_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a rough estimate of the largest 3D texture that the GL can handle.
                        The value must be at least 64.
                        Use <code class="constant">GL_PROXY_TEXTURE_3D</code> to determine if a texture is too large.
                        See <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_ARRAY_TEXTURE_LAYERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value indicates the maximum number of layers allowed in an array texture, and must be at least 256.
                        See <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_CLIP_DISTANCES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of application-defined clipping distances. The value must be at least 8.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COLOR_TEXTURE_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of samples in a color multisample texture.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to all active shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of words for fragment shader uniform variables in all uniform
                        blocks (including default). The value must be at least 1.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of words for geometry shader uniform variables in all uniform
                        blocks (including default). The value must be at least 1.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the vertex shader and the fragment processor combined.
                        If both the vertex shader and the fragment processing stage access the same texture image
                        unit, then that counts as using two texture image units against this limit.
                        The value must be at least 48.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per program.  The value must be at least 70.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of words for vertex shader uniform variables in all uniform
                        blocks (including default). The value must be at least 1.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_CUBE_MAP_TEXTURE_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value gives a rough estimate of the largest cube-map texture that
                        the GL can handle. The value must be at least 1024.
                        Use <code class="constant">GL_PROXY_TEXTURE_CUBE_MAP</code>
                        to determine if a texture is too large.
                        See <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_DEPTH_TEXTURE_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of samples in a multisample depth or depth-stencil texture.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_DRAW_BUFFERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum number
                        of simultaneous outputs that may be written in a fragment shader.
                        The value must be at least 8.
                        See <a class="citerefentry" href="glDrawBuffers"><span class="citerefentry"><span class="refentrytitle">glDrawBuffers</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_DUAL_SOURCE_DRAW_BUFFERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum number
                        of active draw buffers when using dual-source  blending. The value must be at least 1.
                        See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a> and
                        <a class="citerefentry" href="glBlendFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glBlendFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_ELEMENTS_INDICES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the recommended maximum number of vertex array indices.
                        See <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_ELEMENTS_VERTICES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the recommended maximum number of vertex array vertices.
                        See <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to fragment shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a fragment shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_INPUT_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of components of the inputs read by the fragment shader, which must be at least 128.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual floating-point, integer, or boolean values that can be held
                        in uniform variable storage for a fragment shader. The value must be at least 1024.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_UNIFORM_VECTORS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual 4-vectors of floating-point, integer, or boolean values
                        that can be held
                        in uniform variable storage for a fragment shader. The value is equal to the value of
                        <code class="constant">GL_MAX_FRAGMENT_UNIFORM_COMPONENTS</code> divided by 4 and must be at least 256.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAGMENT_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per fragment shader.  The value must be at least 12.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAMEBUFFER_WIDTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum width for a framebuffer that has no attachments, which must be at least 16384.
                        See <a class="citerefentry" href="glFramebufferParameter"><span class="citerefentry"><span class="refentrytitle">glFramebufferParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAMEBUFFER_HEIGHT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum height for a framebuffer that has no attachments, which must be at least 16384.
                        See <a class="citerefentry" href="glFramebufferParameter"><span class="citerefentry"><span class="refentrytitle">glFramebufferParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAMEBUFFER_LAYERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of layers for a framebuffer that has no attachments, which must be at least 2048.
                        See <a class="citerefentry" href="glFramebufferParameter"><span class="citerefentry"><span class="refentrytitle">glFramebufferParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_FRAMEBUFFER_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum samples in a framebuffer that has no attachments, which must be at least 4.
                        See <a class="citerefentry" href="glFramebufferParameter"><span class="citerefentry"><span class="refentrytitle">glFramebufferParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to geometry shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a geometry shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_INPUT_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of components of inputs read by a geometry shader, which must be at least 64.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_OUTPUT_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of components of outputs written by a geometry shader, which must be at least 128.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the geometry shader. The value must be at least 16.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per geometry shader.  The value must be at least 12.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_GEOMETRY_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual floating-point, integer, or boolean values that can be held
                        in uniform variable storage for a geometry shader. The value must be at least 1024.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_INTEGER_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of samples supported in integer format multisample buffers.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MIN_MAP_BUFFER_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the minimum alignment in basic machine units of pointers returned from<a class="citerefentry" href="glMapBuffer"><span class="citerefentry"><span class="refentrytitle">glMapBuffer</span></span></a>
                        and <a class="citerefentry" href="glMapBufferRange"><span class="citerefentry"><span class="refentrytitle">glMapBufferRange</span></span></a>. This value must be a power of two and must
                        be at least 64.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_LABEL_LENGTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum length of a label that may be assigned to an object.
                        See <a class="citerefentry" href="glObjectLabel"><span class="citerefentry"><span class="refentrytitle">glObjectLabel</span></span></a> and
                        <a class="citerefentry" href="glObjectPtrLabel"><span class="citerefentry"><span class="refentrytitle">glObjectPtrLabel</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_PROGRAM_TEXEL_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum texel offset allowed in a texture lookup, which must be at least 7.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MIN_PROGRAM_TEXEL_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the minimum texel offset allowed in a texture lookup, which must be at most -8.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_RECTANGLE_TEXTURE_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value gives a rough estimate of the largest rectangular texture that
                        the GL can handle. The value must be at least 1024.
                        Use <code class="constant">GL_PROXY_TEXTURE_RECTANGLE</code>
                        to determine if a texture is too large.
                        See <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_RENDERBUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value indicates the maximum supported size for renderbuffers.
                        See <a class="citerefentry" href="glFramebufferRenderbuffer"><span class="citerefentry"><span class="refentrytitle">glFramebufferRenderbuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_SAMPLE_MASK_WORDS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of sample mask words.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_SERVER_WAIT_TIMEOUT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum <a class="citerefentry" href="glWaitSync"><span class="citerefentry"><span class="refentrytitle">glWaitSync</span></span></a> timeout interval.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of shader storage buffer binding points on the context, which must be at least 8.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to tessellation control shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to tessellation evaluation shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a tessellation control shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a tessellation evaluation shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TEXTURE_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value gives the maximum number of texels allowed in the texel array of a texture buffer object.
                        Value must be at least 65536.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the fragment shader.
                        The value must be at least 16.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TEXTURE_LOD_BIAS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum, absolute value of the texture level-of-detail bias.  The
                        value must be at least 2.0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_TEXTURE_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        The value gives a rough estimate of the largest texture that
                        the GL can handle. The value must be at least 1024.
                        Use a proxy texture target such as <code class="constant">GL_PROXY_TEXTURE_1D</code> or <code class="constant">GL_PROXY_TEXTURE_2D</code>
                        to determine if a texture is too large.
                        See <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a> and <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_UNIFORM_BUFFER_BINDINGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform buffer binding points on the context, which must be at least 36.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_UNIFORM_BLOCK_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum size in basic machine units of a uniform block, which must be at least 16384.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_UNIFORM_LOCATIONS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of explicitly assignable uniform locations, which must be at least 1024.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VARYING_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number components for varying variables, which must be at least 60.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VARYING_VECTORS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number 4-vectors for varying variables, which is equal to the value of
                        <code class="constant">GL_MAX_VARYING_COMPONENTS</code> and must be at least 15.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VARYING_FLOATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of interpolators available for processing varying variables used by
                        vertex and fragment shaders. This value represents the number of individual floating-point
                        values that can be interpolated; varying variables declared as vectors, matrices, and arrays
                        will all consume multiple interpolators. The value must be at least 32.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_ATOMIC_COUNTERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum number of atomic counters available to vertex shaders.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_ATTRIBS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of 4-component generic vertex attributes accessible to a vertex shader.
                        The value must be at least 16.
                        See <a class="citerefentry" href="glVertexAttrib"><span class="citerefentry"><span class="refentrytitle">glVertexAttrib</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of active shader storage blocks that may be accessed by a vertex shader.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum supported texture image units that
                        can be used to access texture maps from the vertex shader. The value may be at least 16.
                        See <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_UNIFORM_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of individual floating-point, integer, or boolean values that can be held
                        in uniform variable storage for a vertex shader. The value must be at least 1024.
                        See <a class="citerefentry" href="glUniform"><span class="citerefentry"><span class="refentrytitle">glUniform</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_UNIFORM_VECTORS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of 4-vectors that may be held in uniform variable storage for the vertex
                        shader. The value of <code class="constant">GL_MAX_VERTEX_UNIFORM_VECTORS</code> is equal to the
                        value of <code class="constant">GL_MAX_VERTEX_UNIFORM_COMPONENTS</code> and must be at least
                        256.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_OUTPUT_COMPONENTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of components of output written by a vertex shader, which must be at least 64.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_UNIFORM_BLOCKS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the maximum number of uniform blocks per vertex shader.  The value must be at least 12.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VIEWPORT_DIMS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns two values:
                        the maximum supported width and height of the viewport.
                        These must be at least as large as the visible dimensions of the display
                        being rendered to.
                        See <a class="citerefentry" href="glViewport"><span class="citerefentry"><span class="refentrytitle">glViewport</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VIEWPORTS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value, the maximum number
                        of simultaneous viewports that are supported.
                        The value must be at least 16.
                        See <a class="citerefentry" href="glViewportIndexed"><span class="citerefentry"><span class="refentrytitle">glViewportIndexed</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MINOR_VERSION</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the minor version number of the OpenGL API supported by the current context.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_NUM_COMPRESSED_TEXTURE_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value indicating the number of available
                        compressed texture formats.  The minimum value is 4.
                        See <a class="citerefentry" href="glCompressedTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCompressedTexImage2D</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_NUM_EXTENSIONS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of extensions supported by the GL implementation for the current context.
                        See <a class="citerefentry" href="glGetString"><span class="citerefentry"><span class="refentrytitle">glGetString</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_NUM_PROGRAM_BINARY_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of program binary formats supported by the implementation.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_NUM_SHADER_BINARY_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of binary shader formats supported by the implementation. If this value is
                        greater than zero, then the implementation supports loading binary shaders. If it is
                        zero, then the loading of binary shaders by the implementation is not supported.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the byte alignment used for writing pixel data to memory. The initial
                        value is 4.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_IMAGE_HEIGHT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the image height used for writing pixel data to memory.  The initial
                        value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_LSB_FIRST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether single-bit
                        pixels being written to memory are written first to the least significant
                        bit of each unsigned byte. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_ROW_LENGTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the row length used for writing pixel data to memory. The initial value is
                        0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_SKIP_IMAGES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of pixel images skipped before the first pixel is written
                        into memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_SKIP_PIXELS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of pixel locations skipped before the first pixel is written
                        into memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_SKIP_ROWS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of rows of pixel locations skipped before the first pixel is written
                        into memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PACK_SWAP_BYTES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether the bytes of
                        two-byte and four-byte pixel indices and components are swapped before being
                        written to memory. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PIXEL_PACK_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_PIXEL_PACK_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_PIXEL_UNPACK_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_FADE_THRESHOLD_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the point size threshold for determining the point size.
                        See <a class="citerefentry" href="glPointParameter"><span class="citerefentry"><span class="refentrytitle">glPointParameter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PRIMITIVE_RESTART_INDEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the current primitive restart index. The initial value is 0.
                        See <a class="citerefentry" href="glPrimitiveRestartIndex"><span class="citerefentry"><span class="refentrytitle">glPrimitiveRestartIndex</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROGRAM_BINARY_FORMATS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> an array of <code class="constant">GL_NUM_PROGRAM_BINARY_FORMATS</code> values,
                        indicating the proram binary formats supported by the implementation.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROGRAM_PIPELINE_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> a single value, the name of the currently bound program pipeline
                        object, or zero if no program pipeline object is bound.
                        See <a class="citerefentry" href="glBindProgramPipeline"><span class="citerefentry"><span class="refentrytitle">glBindProgramPipeline</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROGRAM_POINT_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether vertex
                        program point size mode is enabled. If enabled, then the
                        point size is taken from the shader built-in <code class="code">gl_PointSize</code>. If disabled,
                        then the point size is taken from the point state as specified
                        by <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>.
                        The initial value is <code class="constant">GL_FALSE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROVOKING_VERTEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the currently selected provoking vertex convention. The initial value is <code class="constant">GL_LAST_VERTEX_CONVENTION</code>.
                        See <a class="citerefentry" href="glProvokingVertex"><span class="citerefentry"><span class="refentrytitle">glProvokingVertex</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the point size as specified by <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>.
                        The initial value is 1.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SIZE_GRANULARITY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the size difference between adjacent supported sizes for antialiased points.
                        See <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POINT_SIZE_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns two values:
                        the smallest and largest supported sizes for antialiased
                        points. The smallest size must be at most 1, and the largest size must
                        be at least 1.
                        See <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_FACTOR</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the scaling factor used to determine the variable offset that is added
                        to the depth value of each fragment generated when a polygon is
                        rasterized. The initial value is 0.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_UNITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value.
                        This value is multiplied by an implementation-specific value and then
                        added to the depth value of each fragment
                        generated when a polygon is rasterized. The initial value is 0.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_FILL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether polygon offset
                        is enabled for polygons in fill mode. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_LINE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether polygon offset
                        is enabled for polygons in line mode. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_POINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether polygon offset
                        is enabled for polygons in point mode. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_SMOOTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether antialiasing of
                        polygons is enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPolygonMode"><span class="citerefentry"><span class="refentrytitle">glPolygonMode</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_SMOOTH_HINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating the mode of the polygon antialiasing
                        hint. The initial value is <code class="constant">GL_DONT_CARE</code>.
                        See <a class="citerefentry" href="glHint"><span class="citerefentry"><span class="refentrytitle">glHint</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_READ_BUFFER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating which color buffer is selected for
                        reading. The initial value is <code class="constant">GL_BACK</code> if there is a back buffer,
                        otherwise it is <code class="constant">GL_FRONT</code>.
                        See
                        <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_RENDERBUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the renderbuffer object
                        currently bound to the target <code class="constant">GL_RENDERBUFFER</code>. If no renderbuffer object
                        is bound to this target, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindRenderbuffer"><span class="citerefentry"><span class="refentrytitle">glBindRenderbuffer</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_BUFFERS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value indicating the number of sample buffers
                        associated with the framebuffer.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_COVERAGE_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single positive floating-point value indicating the
                        current sample coverage value.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_COVERAGE_INVERT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating if the temporary
                        coverage value should be inverted.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_MASK_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns one value, the 32-bit sub-word of the sample mask
												that specifies which samples to update. The index must be less than <code class="constant">GL_MAX_SAMPLE_MASK_WORDS</code>.
												The initial value is all 1's.
                        See <a class="citerefentry" href="glSampleMaski"><span class="citerefentry"><span class="refentrytitle">glSampleMaski</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the sampler object
                        currently bound to the active texture unit.  The initial value is 0.
                        See <a class="citerefentry" href="glBindSampler"><span class="citerefentry"><span class="refentrytitle">glBindSampler</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value indicating the coverage mask size.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SCISSOR_BOX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns four values:
                        the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates of the scissor box,
                        followed by its width and height.
                        Initially the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates are both 0 and the
                        width and height are set to the size of the window.
                        See <a class="citerefentry" href="glScissor"><span class="citerefentry"><span class="refentrytitle">glScissor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SCISSOR_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether scissoring is
                        enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glScissor"><span class="citerefentry"><span class="refentrytitle">glScissor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_COMPILER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether an online shader
                        compiler is present in the implementation. All desktop OpenGL implementations must support
                        online shader compilations, and therefore the value of <code class="constant">GL_SHADER_COMPILER</code>
                        will always be <code class="constant">GL_TRUE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_STORAGE_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with non-indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegerv</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_SHADER_STORAGE_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        bound to the indexed shader storage buffer binding points. The initial value is 0 for all targets.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>, <a class="citerefentry" href="glBindBufferBase"><span class="citerefentry"><span class="refentrytitle">glBindBufferBase</span></span></a>, and
                        <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the minimum required alignment
                        for shader storage buffer sizes and offset.  The initial value is 1.
                        See <a class="citerefentry" href="glShaderStorateBlockBinding"><span class="citerefentry"><span class="refentrytitle">glShaderStorateBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_STORAGE_BUFFER_START</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the start offset of the binding range for each
                        indexed shader storage buffer binding. The initial value is 0 for all bindings.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SHADER_STORAGE_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the size of the binding range for each
                        indexed shader storage buffer binding. The initial value is 0 for all bindings.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SMOOTH_LINE_WIDTH_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a pair of values indicating the range of
                        widths supported for smooth (antialiased) lines. See <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SMOOTH_LINE_WIDTH_GRANULARITY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value indicating the level of
                        quantization applied to smooth line width parameters.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_FAIL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken for back-facing polygons when the stencil
                        test fails. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_FUNC</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what function is used for back-facing polygons to compare the
                        stencil reference value with the stencil buffer value. The initial value
                        is <code class="constant">GL_ALWAYS</code>.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_PASS_DEPTH_FAIL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken for back-facing polygons when the stencil
                        test passes,
                        but the depth test fails. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_PASS_DEPTH_PASS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken for back-facing polygons when the stencil
                        test passes and the depth test passes. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_REF</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the reference value that is compared with the contents of the stencil
                        buffer for back-facing polygons. The initial value is 0.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_VALUE_MASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the mask that is used for back-facing polygons to mask both the stencil reference value and the
                        stencil buffer value before they are compared. The initial value is all 1's.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_BACK_WRITEMASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the mask that controls writing of the stencil bitplanes for back-facing polygons. The initial value
                        is all 1's.
                        See <a class="citerefentry" href="glStencilMaskSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilMaskSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_CLEAR_VALUE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the index to which the stencil bitplanes are cleared. The initial value is
                        0.
                        See <a class="citerefentry" href="glClearStencil"><span class="citerefentry"><span class="refentrytitle">glClearStencil</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_FAIL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken when the stencil
                        test fails. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_FUNC</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what function is used to compare the
                        stencil reference value with the stencil buffer value. The initial value
                        is <code class="constant">GL_ALWAYS</code>.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_PASS_DEPTH_FAIL</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken when the stencil
                        test passes,
                        but the depth test fails. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_PASS_DEPTH_PASS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        a symbolic constant indicating what action is taken when the stencil
                        test passes and the depth test passes. The initial value is <code class="constant">GL_KEEP</code>.
                        See <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilOpSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilOpSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_REF</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the reference value that is compared with the contents of the stencil
                        buffer. The initial value is 0.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether stencil testing
                        of fragments is enabled. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a> and <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_VALUE_MASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the mask that is used to mask both the stencil reference value and the
                        stencil buffer value before they are compared. The initial value is all 1's.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilFuncSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilFuncSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_WRITEMASK</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the mask that controls writing of the stencil bitplanes. The initial value
                        is all 1's.
                        See <a class="citerefentry" href="glStencilMask"><span class="citerefentry"><span class="refentrytitle">glStencilMask</span></span></a>.
                        This stencil state only affects non-polygons
                        and front-facing polygons.  Back-facing polygons use separate stencil state.
                        See <a class="citerefentry" href="glStencilMaskSeparate"><span class="citerefentry"><span class="refentrytitle">glStencilMaskSeparate</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STEREO</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether stereo buffers
                        (left and right) are supported.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SUBPIXEL_BITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        an estimate of the number of bits of subpixel resolution that are used to
                        position rasterized geometry in window coordinates. The value must be at least 4.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_1D</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_1D</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_1D_ARRAY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_1D_ARRAY</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_2D</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_2D</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_2D_ARRAY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_2D_ARRAY</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_2D_MULTISAMPLE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_3D</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_3D</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_BUFFER</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_BUFFER</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_CUBE_MAP</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_CUBE_MAP</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BINDING_RECTANGLE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the texture
                        currently bound to the target <code class="constant">GL_TEXTURE_RECTANGLE</code>. The initial value is 0.
                        See <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_COMPRESSION_HINT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value indicating the mode of the texture
                        compression hint.  The initial value is <code class="constant">GL_DONT_CARE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the minimum required alignment
                        for texture buffer sizes and offset.  The initial value is 1.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TIMESTAMP</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the 64-bit value of the current
                        GL time.
                        See <a class="citerefentry" href="glQueryCounter"><span class="citerefentry"><span class="refentrytitle">glQueryCounter</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with non-indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegerv</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        bound to the indexed transform feedback attribute stream. The initial value is 0 for all targets.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>, <a class="citerefentry" href="glBindBufferBase"><span class="citerefentry"><span class="refentrytitle">glBindBufferBase</span></span></a>, and
                        <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER_START</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the start offset of the binding range for each
                        transform feedback attribute stream. The initial value is 0 for all streams.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the size of the binding range for each
                        transform feedback attribute stream. The initial value is 0 for all streams.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNIFORM_BUFFER_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with non-indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegerv</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        currently bound to the target <code class="constant">GL_UNIFORM_BUFFER</code>. If no buffer object
                        is bound to this target, 0 is returned.
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the buffer object
                        bound to the indexed uniform buffer binding point. The initial value is 0 for all targets.
                        See <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>, <a class="citerefentry" href="glBindBufferBase"><span class="citerefentry"><span class="refentrytitle">glBindBufferBase</span></span></a>, and
                        <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the minimum required alignment
                        for uniform buffer sizes and offset.  The initial value is 1.
                        See <a class="citerefentry" href="glUniformBlockBinding"><span class="citerefentry"><span class="refentrytitle">glUniformBlockBinding</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNIFORM_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the size of the binding range for each
                        indexed uniform buffer binding. The initial value is 0 for all bindings.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNIFORM_BUFFER_START</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetInteger64i_v</code>),
                        <em class="parameter"><code>data</code></em> returns a single value, the start offset of the binding range for each
                        indexed uniform buffer binding. The initial value is 0 for all bindings.
                        See <a class="citerefentry" href="glBindBufferRange"><span class="citerefentry"><span class="refentrytitle">glBindBufferRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_ALIGNMENT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the byte alignment used for reading pixel data from memory. The initial
                        value is 4.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_IMAGE_HEIGHT</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the image height used for reading pixel data from memory.  The initial
                        is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_LSB_FIRST</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether single-bit
                        pixels being read from memory are read first from the least significant
                        bit of each unsigned byte. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_ROW_LENGTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the row length used for reading pixel data from memory. The initial value
                        is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_SKIP_IMAGES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of pixel images skipped before the first pixel is read
                        from memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_SKIP_PIXELS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of pixel locations skipped before the first pixel is read
                        from memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_SKIP_ROWS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the number of rows of pixel locations skipped before the first pixel is read
                        from memory. The initial value is 0.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_UNPACK_SWAP_BYTES</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single boolean value indicating whether the bytes of
                        two-byte and four-byte pixel indices and components are swapped after being
                        read from memory. The initial value is <code class="constant">GL_FALSE</code>.
                        See <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VERTEX_ARRAY_BINDING</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the name of the vertex array object
                        currently bound to the context. If no vertex array object
                        is bound to the context, 0 is returned.  The initial value is 0.
                        See <a class="citerefentry" href="glBindVertexArray"><span class="citerefentry"><span class="refentrytitle">glBindVertexArray</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VERTEX_BINDING_DIVISOR</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed forms. <em class="parameter"><code>data</code></em> returns a single integer value representing the instance step
                        divisor of the first element in the bound buffer's data store for vertex attribute bound to <em class="parameter"><code>index</code></em>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VERTEX_BINDING_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed forms. <em class="parameter"><code>data</code></em> returns a single integer value representing the byte offset
                        of the first element in the bound buffer's data store for vertex attribute bound to <em class="parameter"><code>index</code></em>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VERTEX_BINDING_STRIDE</code>
              </span>
            </dt>
            <dd>
              <p>
                        Accepted by the indexed forms. <em class="parameter"><code>data</code></em> returns a single integer value representing the byte offset
                        between the start of each element in the bound buffer's data store for vertex attribute bound to <em class="parameter"><code>index</code></em>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value containing the maximum offset that may be added to a vertex binding
                        offset.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_VERTEX_ATTRIB_BINDINGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single integer value containing the maximum number of vertex buffers that may be bound.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VIEWPORT</code>
              </span>
            </dt>
            <dd>
              <p>
                        When used with non-indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegerv</code>),
                        <em class="parameter"><code>data</code></em> returns four values:
                        the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates of the viewport, followed by its width and height.
                        Initially the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates are both set to 0,
                        and the width and height are set to the width and height of the window into
                        which the GL will do its rendering.
                        See <a class="citerefentry" href="glViewport"><span class="citerefentry"><span class="refentrytitle">glViewport</span></span></a>.
                    </p>
              <p>
                        When used with indexed variants of <code class="function">glGet</code> (such as <code class="function">glGetIntegeri_v</code>),
                        <em class="parameter"><code>data</code></em> returns four values:
                        the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates of the indexed viewport, followed by its width and height.
                        Initially the
                        <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
                        and
                        <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
                        window coordinates are both set to 0,
                        and the width and height are set to the width and height of the window into
                        which the GL will do its rendering.
                        See <a class="citerefentry" href="glViewportIndexedf"><span class="citerefentry"><span class="refentrytitle">glViewportIndexedf</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VIEWPORT_BOUNDS_RANGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns two values, the minimum and maximum viewport bounds range.
                        The minimum range should be at least [-32768, 32767].
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VIEWPORT_INDEX_PROVOKING_VERTEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns one value,
                        the implementation dependent specifc vertex of a primitive that is used to select the viewport index.
                        If the value returned is equivalent to <code class="constant">GL_PROVOKING_VERTEX</code>, then the vertex
                        selection follows the convention specified by
                        <a class="citerefentry" href="glProvokingVertex"><span class="citerefentry"><span class="refentrytitle">glProvokingVertex</span></span></a>.
                        If the value returned is equivalent to <code class="constant">GL_FIRST_VERTEX_CONVENTION</code>, then the
                        selection is always taken from the first vertex in the primitive.
                        If the value returned is equivalent to <code class="constant">GL_LAST_VERTEX_CONVENTION</code>, then the
                        selection is always taken from the last vertex in the primitive.
                        If the value returned is equivalent to <code class="constant">GL_UNDEFINED_VERTEX</code>, then the
                        selection is not guaranteed to be taken from any specific vertex in the primitive.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_VIEWPORT_SUBPIXEL_BITS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the number of bits of sub-pixel precision which the GL
                        uses to interpret the floating point viewport bounds. The minimum value is 0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MAX_ELEMENT_INDEX</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>data</code></em> returns a single value, the maximum index that may be specified during the
                        transfer of generic vertex attributes to the GL.
                    </p>
            </dd>
          </dl>
        </div>
        <p>
            Many of the boolean parameters can also be queried more easily using
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The following parameters return the associated value for the active texture unit:
            <code class="constant">GL_TEXTURE_1D</code>, <code class="constant">GL_TEXTURE_BINDING_1D</code>,
            <code class="constant">GL_TEXTURE_2D</code>, <code class="constant">GL_TEXTURE_BINDING_2D</code>,
            <code class="constant">GL_TEXTURE_3D</code> and <code class="constant">GL_TEXTURE_BINDING_3D</code>.
        </p>
        <p>
            <code class="constant">GL_MAX_VIEWPORTS</code>, <code class="constant">GL_VIEWPORT_SUBPIXEL_BITS</code>,
            <code class="constant">GL_VIEWPORT_BOUNDS_RANGE</code>, <code class="constant">GL_LAYER_PROVOKING_VERTEX</code>,
            and <code class="constant">GL_VIEWPORT_INDEX_PROVOKING_VERTEX</code>
            are available only if the GL version is 4.1 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_VERTEX_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_GEOMETRY_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_FRAMGENT_ATOMIC_COUNTERS</code>, and
            <code class="constant">GL_MIN_MAP_BUFFER_ALIGNMENT</code> are accepted by <em class="parameter"><code>pname</code></em>
            only if the GL version is 4.2 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_ELEMENT_INDEX</code> is accepted by <em class="parameter"><code>pname</code></em> only
            if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_COMPUTE_UNIFORM_BLOCKS</code>, <code class="constant">GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS</code>,
            <code class="constant">GL_MAX_COMPUTE_UNIFORM_COMPONENTS</code>, <code class="constant">GL_MAX_COMPUTE_ATOMIC_COUNTERS</code>,
            <code class="constant">GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS</code>, <code class="constant">GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS</code>,
            <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS</code>, <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_COUNT</code>, and
            <code class="constant">GL_MAX_COMPUTE_WORK_GROUP_SIZE</code> and <code class="constant">GL_DISPATCH_INDIRECT_BUFFER_BINDING</code> are available only if the GL version
            is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_DEBUG_GROUP_STACK_DEPTH</code>, <code class="constant">GL_DEBUG_GROUP_STACK_DEPTH</code> and <code class="constant">GL_MAX_LABEL_LENGTH</code> are accepted only if
            the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_UNIFORM_LOCATIONS</code> is accepted only if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_FRAMEBUFFER_WIDTH</code>, <code class="constant">GL_MAX_FRAMEBUFFER_HEIGHT</code>, <code class="constant">GL_MAX_FRAMEBUFFER_LAYERS</code>,
            and <code class="constant">GL_MAX_FRAMEBUFFER_SAMPLES</code> are available only if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS</code>, <code class="constant">GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS</code>,
            <code class="constant">GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS</code>, <code class="constant">GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS</code>,
            <code class="constant">GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS</code>, and <code class="constant">GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS</code> are available
            only if the GL version is 4.3 or higher.
        </p>
        <p>
            <code class="constant">GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT</code> is available only if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_VERTEX_BINDING_DIVISOR</code>, <code class="constant">GL_VERTEX_BINDING_OFFSET</code>, <code class="constant">GL_VERTEX_BINDING_STRIDE</code>,
            <code class="constant">GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET</code> and <code class="constant">GL_MAX_VERTEX_ATTRIB_BINDINGS</code> are available only if
            the GL version is 4.3 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>pname</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated on any of <code class="function">glGetBooleani_v</code>,
            <code class="function">glGetIntegeri_v</code>, or <code class="function">glGetInteger64i_v</code> if
            <em class="parameter"><code>index</code></em> is outside of the valid range for the indexed state <em class="parameter"><code>target</code></em>.
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
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glGetBooleani_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetBooleanv</code>
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
                  <code class="function">glGetDoublei_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glGetDoublev</code>
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
                  <code class="function">glGetFloati_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glGetFloatv</code>
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
                  <code class="function">glGetInteger64i_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetInteger64v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetIntegeri_v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetIntegerv</code>
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
            <a class="citerefentry" href="glGetActiveUniform"><span class="citerefentry"><span class="refentrytitle">glGetActiveUniform</span></span></a>,
            <a class="citerefentry" href="glGetAttachedShaders"><span class="citerefentry"><span class="refentrytitle">glGetAttachedShaders</span></span></a>,
            <a class="citerefentry" href="glGetAttribLocation"><span class="citerefentry"><span class="refentrytitle">glGetAttribLocation</span></span></a>,
            <a class="citerefentry" href="glGetBufferParameter"><span class="citerefentry"><span class="refentrytitle">glGetBufferParameter</span></span></a>,
            <a class="citerefentry" href="glGetBufferPointerv"><span class="citerefentry"><span class="refentrytitle">glGetBufferPointerv</span></span></a>,
            <a class="citerefentry" href="glGetBufferSubData"><span class="citerefentry"><span class="refentrytitle">glGetBufferSubData</span></span></a>,
            <a class="citerefentry" href="glGetCompressedTexImage"><span class="citerefentry"><span class="refentrytitle">glGetCompressedTexImage</span></span></a>,
            <a class="citerefentry" href="glGetError"><span class="citerefentry"><span class="refentrytitle">glGetError</span></span></a>,
            <a class="citerefentry" href="glGetProgram"><span class="citerefentry"><span class="refentrytitle">glGetProgram</span></span></a>,
            <a class="citerefentry" href="glGetProgramInfoLog"><span class="citerefentry"><span class="refentrytitle">glGetProgramInfoLog</span></span></a>,
            <a class="citerefentry" href="glGetQueryiv"><span class="citerefentry"><span class="refentrytitle">glGetQueryiv</span></span></a>,
            <a class="citerefentry" href="glGetQueryObject"><span class="citerefentry"><span class="refentrytitle">glGetQueryObject</span></span></a>,
            <a class="citerefentry" href="glGetShader"><span class="citerefentry"><span class="refentrytitle">glGetShader</span></span></a>,
            <a class="citerefentry" href="glGetShaderInfoLog"><span class="citerefentry"><span class="refentrytitle">glGetShaderInfoLog</span></span></a>,
            <a class="citerefentry" href="glGetShaderSource"><span class="citerefentry"><span class="refentrytitle">glGetShaderSource</span></span></a>,
            <a class="citerefentry" href="glGetString"><span class="citerefentry"><span class="refentrytitle">glGetString</span></span></a>,
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>,
            <a class="citerefentry" href="glGetTexLevelParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexLevelParameter</span></span></a>,
            <a class="citerefentry" href="glGetTexParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexParameter</span></span></a>,
            <a class="citerefentry" href="glGetUniform"><span class="citerefentry"><span class="refentrytitle">glGetUniform</span></span></a>,
            <a class="citerefentry" href="glGetUniformLocation"><span class="citerefentry"><span class="refentrytitle">glGetUniformLocation</span></span></a>,
            <a class="citerefentry" href="glGetVertexAttrib"><span class="citerefentry"><span class="refentrytitle">glGetVertexAttrib</span></span></a>,
            <a class="citerefentry" href="glGetVertexAttribPointerv"><span class="citerefentry"><span class="refentrytitle">glGetVertexAttribPointerv</span></span></a>,
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGet.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetInteger64i_v glad_glGetInteger64i_v
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 *params);
GLAPI PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetBufferParameter'>OpenGL 4</a><br /><a  href='../gl3/glGetBufferParameter'>OpenGL 3</a><br /><a  href='../es3/glGetBufferParameter'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glGetBufferParameter</h1>
    <div class="refentry" id="glGetBufferParameter">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetBufferParameter — return parameters of a buffer object</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetBufferParameteriv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">value</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetBufferParameteri64v</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">value</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint64 * <var class="pdparam">data</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetNamedBufferParameteriv</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">buffer</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint *<var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetNamedBufferParameteri64v</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">buffer</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint64 *<var class="pdparam">params</var><code>)</code>;</td>
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
                    Specifies the target to which the buffer object is bound
                    for <code class="function">glGetBufferParameteriv</code> and
                    <code class="function">glGetBufferParameteri64v</code>. Must be
                    one of the buffer binding targets in the following
                    table:
                </p>
              <div class="informaltable">
                <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
                  <colgroup>
                    <col style="text-align: left; " class="col1"/>
                    <col style="text-align: left; " class="col2"/>
                  </colgroup>
                  <thead>
                    <tr>
                      <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <span class="bold">
                          <strong>Buffer Binding Target</strong>
                        </span>
                      </th>
                      <th style="text-align: left; border-bottom: 2px solid ; ">
                        <span class="bold">
                          <strong>Purpose</strong>
                        </span>
                      </th>
                    </tr>
                  </thead>
                  <tbody>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_ARRAY_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Vertex attributes</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_ATOMIC_COUNTER_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Atomic counter storage</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_COPY_READ_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Buffer copy source</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_COPY_WRITE_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Buffer copy destination</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_DISPATCH_INDIRECT_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Indirect compute dispatch commands</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_DRAW_INDIRECT_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Indirect command arguments</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_ELEMENT_ARRAY_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Vertex array indices</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_PIXEL_PACK_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Pixel read target</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_PIXEL_UNPACK_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Texture data source</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_QUERY_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Query result buffer</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_SHADER_STORAGE_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Read-write storage for shaders</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_TEXTURE_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Texture data buffer</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                        <code class="constant">GL_TRANSFORM_FEEDBACK_BUFFER</code>
                      </td>
                      <td style="text-align: left; border-bottom: 2px solid ; ">Transform feedback buffer</td>
                    </tr>
                    <tr>
                      <td style="text-align: left; border-right: 2px solid ; ">
                        <code class="constant">GL_UNIFORM_BUFFER</code>
                      </td>
                      <td style="text-align: left; ">Uniform block storage</td>
                    </tr>
                  </tbody>
                </table>
              </div>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>buffer</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of the buffer object for
                    <code class="function">glGetNamedBufferParameteriv</code> and
                    <code class="function">glGetNamedBufferParameteri64v</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>value</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of the buffer object parameter to
                    query.
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
                    Returns the requested parameter.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            These functions return in <em class="parameter"><code>data</code></em> a selected
            parameter of the specified buffer object.
        </p>
        <p>
            <em class="parameter"><code>pname</code></em> names a specific buffer object
            parameter, as follows:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_ACCESS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns the access
                        policy set while mapping the buffer object (the
                        value of the <em class="parameter"><code>access</code></em> parameter
                        enum passed to <code class="function">glMapBuffer</code>). If
                        the buffer was mapped with
                        <code class="function">glMapBufferRange</code>, the access
                        policy is determined by translating the bits in that
                        <em class="parameter"><code>access</code></em> parameter to one of
                        the supported enums for
                        <code class="function">glMapBuffer</code> as described in the
                        OpenGL Specification.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_ACCESS_FLAGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns the access
                        policy set while mapping the buffer object (the
                        value of the <em class="parameter"><code>access</code></em> parameter
                        bitfield passed to
                        <code class="function">glMapBufferRange</code>). If the
                        buffer was mapped with
                        <code class="function">glMapBuffer</code>, the access policy
                        is determined by translating the enums in that
                        <em class="parameter"><code>access</code></em> parameter to the
                        corresponding bits for
                        <code class="function">glMapBufferRange</code> as described
                        in the OpenGL Specification. The initial value is
                        zero.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_IMMUTABLE_STORAGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns a boolean flag
                        indicating whether the buffer object is immutable.
                        The initial value is <code class="constant">GL_FALSE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_MAPPED</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns a flag
                        indicating whether the buffer object is currently
                        mapped. The initial value is
                        <code class="constant">GL_FALSE</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_MAP_LENGTH</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns the length of
                        the mapping into the buffer object established with
                        <code class="function">glMapBuffer*</code>. The
                        <code class="function">i64v</code> versions of these queries
                        should be used for this parameter. The initial value
                        is zero.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_MAP_OFFSET</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns the offset of
                        the mapping into the buffer object established with
                        <code class="function">glMapBuffer*</code>. The
                        <code class="function">i64v</code> versions of these queries
                        should be used for this parameter. The initial value
                        is zero.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns the size of
                        the buffer object, measured in bytes. The initial
                        value is 0.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_STORAGE_FLAGS</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns a bitfield
                        indicating the storage flags for the buffer object.
                        If the buffer object is immutable, the value
                        returned will be that specified when the data store
                        was established with
                        <code class="function">glBufferStorage</code>. If the data
                        store was established with
                        <code class="function">glBufferData</code>, the value will be
                        <code class="constant">GL_MAP_READ_BIT</code> |
                        <code class="constant">GL_MAP_WRITE_BIT</code> |
                        <code class="constant">GL_DYNAMIC_STORAGE_BIT</code> |
                        <code class="constant">GL_MAP_WRITE_BIT</code>. The initial
                        value is zero.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_BUFFER_USAGE</code>
              </span>
            </dt>
            <dd>
              <p>
                        <em class="parameter"><code>params</code></em> returns the buffer
                        object's usage pattern. The initial value is
                        <code class="constant">GL_STATIC_DRAW</code>.
                    </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            If an error is generated, no change is made to the contents of
            <em class="parameter"><code>data</code></em>.
        </p>
        <p>
            The <code class="constant">GL_ATOMIC_COUNTER_BUFFER</code> target is
            available only if the GL version is 4.2 or greater.
        </p>
        <p>
            The <code class="constant">GL_DISPATCH_INDIRECT_BUFFER</code> and
            <code class="constant">GL_SHADER_STORAGE_BUFFER</code> targets are
            available only if the GL version is 4.3 or greater.
        </p>
        <p>
            The <code class="constant">GL_QUERY_BUFFER</code> target is available
            only if the GL version is 4.4 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated by
            <code class="function">glGetBufferParameter*</code> if
            <em class="parameter"><code>target</code></em> is not one of the accepted buffer
            targets.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glGetBufferParameter*</code> if
            zero is bound to <em class="parameter"><code>target</code></em>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glGetNamedBufferParameter*</code> if
            <em class="parameter"><code>buffer</code></em> is not the name of an existing
            buffer object.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if
            <em class="parameter"><code>pname</code></em> is not one of the buffer object
            parameter names described above.
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
                  <code class="function">glGetBufferParameteri64v</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glGetBufferParameteriv</code>
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
                  <code class="function">glGetNamedBufferParameteri64v</code>
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
                  <code class="function">glGetNamedBufferParameteriv</code>
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
            <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>,
            <a class="citerefentry" href="glBufferData"><span class="citerefentry"><span class="refentrytitle">glBufferData</span></span></a>,
            <a class="citerefentry" href="glGetBufferPointerv"><span class="citerefentry"><span class="refentrytitle">glGetBufferPointerv</span></span></a>,
            <a class="citerefentry" href="glMapBuffer"><span class="citerefentry"><span class="refentrytitle">glMapBuffer</span></span></a>,
            <a class="citerefentry" href="glUnmapBuffer"><span class="citerefentry"><span class="refentrytitle">glUnmapBuffer</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2005 Addison-Wesley.
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetBufferParameter.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetBufferParameteri64v glad_glGetBufferParameteri64v
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glFramebufferTexture'>OpenGL 4</a><br /><a  href='../gl3/glFramebufferTexture'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glFramebufferTexture</h1>
    <div class="refentry" id="glFramebufferTexture">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glFramebufferTexture</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">attachment</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glFramebufferTexture1D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">attachment</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">textarget</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glFramebufferTexture2D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">attachment</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">textarget</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glFramebufferTexture3D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">attachment</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">textarget</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">layer</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glNamedFramebufferTexture</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">framebuffer</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">attachment</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var><code>)</code>;</td>
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
                    Specifies the target to which the framebuffer is bound
                    for all commands <span class="emphasis"><em>except</em></span>
                    <code class="function">glNamedFramebufferTexture</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>framebuffer</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of the framebuffer object for
                    <code class="function">glNamedFramebufferTexture</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>attachment</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the attachment point of the framebuffer.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>textarget</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    For <code class="function">glFramebufferTexture1D</code>,
                    <code class="function">glFramebufferTexture2D</code> and
                    <code class="function">glFramebufferTexture3D</code>, specifies
                    what type of texture is expected in the
                    <em class="parameter"><code>texture</code></em> parameter, or for cube
                    map textures, which face is to be attached.
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
                    Specifies the name of an existing texture object to
                    attach.
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
                    Specifies the mipmap level of the texture object to
                    attach.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            These commands attach a selected mipmap level or image of a
            texture object as one of the logical buffers of the specified
            framebuffer object. Textures cannot be attached to the default
            draw and read framebuffer, so they are not valid targets of
            these commands.
        </p>
        <p>
            For all commands <span class="emphasis"><em>except</em></span>
            <code class="function">glNamedFramebufferTexture</code>, the framebuffer
            object is that bound to <em class="parameter"><code>target</code></em>, which
            must be <code class="constant">GL_DRAW_FRAMEBUFFER</code>,
            <code class="constant">GL_READ_FRAMEBUFFER</code>, or
            <code class="constant">GL_FRAMEBUFFER</code>.
            <code class="constant">GL_FRAMEBUFFER</code> is equivalent to
            <code class="constant">GL_DRAW_FRAMEBUFFER</code>.
        </p>
        <p>
            For <code class="function">glNamedFramebufferTexture</code>,
            <em class="parameter"><code>framebuffer</code></em> is the name of the
            framebuffer object.
        </p>
        <p>
            <em class="parameter"><code>attachment</code></em> specifies the logical
            attachment of the framebuffer and must be
            <code class="constant">GL_COLOR_ATTACHMENT</code><span class="emphasis"><em>i</em></span>,
            <code class="constant">GL_DEPTH_ATTACHMENT</code>,
            <code class="constant">GL_STENCIL_ATTACHMENT</code> or
            <code class="constant">GL_DEPTH_STENCIL_ATTACHMENT</code>.
            <span class="emphasis"><em>i</em></span> in
            <code class="constant">GL_COLOR_ATTACHMENT</code><span class="emphasis"><em>i</em></span>
            may range from zero to the value of
            <code class="constant">GL_MAX_COLOR_ATTACHMENTS</code> minus one.
            Attaching a level of a texture to
            <code class="constant">GL_DEPTH_STENCIL_ATTACHMENT</code> is equivalent
            to attaching that level to both the
            <code class="constant">GL_DEPTH_ATTACHMENT</code>
            <span class="emphasis"><em>and</em></span> the
            <code class="constant">GL_STENCIL_ATTACHMENT</code> attachment points
            simultaneously.
        </p>
        <p>
            For <code class="function">glFramebufferTexture1D</code>,
            <code class="function">glFramebufferTexture2D</code> and
            <code class="function">glFramebufferTexture3D</code>,
            <em class="parameter"><code>textarget</code></em> specifies what type of texture
            is named by <em class="parameter"><code>texture</code></em>, and for cube map
            textures, specifies the face that is to be attached. If
            <em class="parameter"><code>texture</code></em> is not zero, it must be the name
            of an existing texture object with effective target
            <em class="parameter"><code>textarget</code></em> unless it is a cube map
            texture, in which case <em class="parameter"><code>textarget</code></em> must be
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>, or
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>.
        </p>
        <p>
            If <em class="parameter"><code>texture</code></em> is non-zero, the specified
            <em class="parameter"><code>level</code></em> of the texture object named
            <em class="parameter"><code>texture</code></em> is attached to the framebuffer
            attachment point named by <em class="parameter"><code>attachment</code></em>. For
            <code class="function">glFramebufferTexture1D</code>,
            <code class="function">glFramebufferTexture2D</code>, and
            <code class="function">glFramebufferTexture3D</code>,
            <em class="parameter"><code>texture</code></em> must be zero or the name of an
            existing texture with an effective target of
            <em class="parameter"><code>textarget</code></em>, or
            <em class="parameter"><code>texture</code></em> must be the name of an existing
            cube-map texture and <em class="parameter"><code>textarget</code></em> must be
            one of <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>, or
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>.
        </p>
        <p>
            If <em class="parameter"><code>textarget</code></em> is
            <code class="constant">GL_TEXTURE_RECTANGLE</code>,
            <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code>, or
            <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code>, then
            <em class="parameter"><code>level</code></em> must be zero.
        </p>
        <p>
            If <em class="parameter"><code>textarget</code></em> is
            <code class="constant">GL_TEXTURE_3D</code>, then
            <em class="parameter"><code>level</code></em> must be greater than or equal to
            zero and less than or equal to $log_2$ of the value of
            <code class="constant">GL_MAX_3D_TEXTURE_SIZE</code>.
        </p>
        <p>
            If <em class="parameter"><code>textarget</code></em> is one of
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>, or
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>, then
            <em class="parameter"><code>level</code></em> must be greater than or equal to
            zero and less than or equal to $log_2$ of the value of
            <code class="constant">GL_MAX_CUBE_MAP_TEXTURE_SIZE</code>.
        </p>
        <p>
            For all other values of <em class="parameter"><code>textarget</code></em>,
            <em class="parameter"><code>level</code></em> must be greater than or equal to
            zero and less than or equal to $log_2$ of the value of
            <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <em class="parameter"><code>layer</code></em> specifies the layer of a
            2-dimensional image within a 3-dimensional texture.
        </p>
        <p>
            For <code class="function">glFramebufferTexture1D</code>, if
            <em class="parameter"><code>texture</code></em> is not zero, then
            <em class="parameter"><code>textarget</code></em> must be
            <code class="constant">GL_TEXTURE_1D</code>. For
            <code class="function">glFramebufferTexture2D</code>, if
            <em class="parameter"><code>texture</code></em> is not zero,
            <em class="parameter"><code>textarget</code></em> must be one of
            <code class="constant">GL_TEXTURE_2D</code>,
            <code class="constant">GL_TEXTURE_RECTANGLE</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>, or
            <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code>. For
            <code class="function">glFramebufferTexture3D</code>, if
            <em class="parameter"><code>texture</code></em> is not zero, then
            <em class="parameter"><code>textarget</code></em> must be
            <code class="constant">GL_TEXTURE_3D</code>.
        </p>
        <p>
            For <code class="function">glFramebufferTexture</code> and
            <code class="function">glNamedFramebufferTexture</code>, if
            <em class="parameter"><code>texture</code></em> is the name of a
            three-dimensional, cube map array, cube map, one- or
            two-dimensional array, or two-dimensional multisample array
            texture, the specified texture level is an array of images, and
            the framebuffer attachment is considered to be
            <span class="emphasis"><em>layered</em></span>.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated by all
            commands accepting a <em class="parameter"><code>target</code></em> parameter if
            it is not one of the accepted framebuffer targets.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by all
            commands accepting a <em class="parameter"><code>target</code></em> parameter if
            zero is bound to that target.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glNamedFramebufferTexture</code> if
            <em class="parameter"><code>framebuffer</code></em> is not the name of an
            existing framebuffer object.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if
            <em class="parameter"><code>attachment</code></em> is not one of the accepted
            attachment points.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if
            <em class="parameter"><code>texture</code></em> is not zero or the name of an
            existing texture object.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if
            <em class="parameter"><code>texture</code></em> is not zero and
            <em class="parameter"><code>level</code></em> is not a supported texture level
            for <em class="parameter"><code>texture</code></em>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated by
            <code class="function">glFramebufferTexture3D</code> if
            <em class="parameter"><code>texture</code></em> is not zero and
            <em class="parameter"><code>layer</code></em> is larger than the value of
            <code class="constant">GL_MAX_3D_TEXTURE_SIZE</code> minus one.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by all
            commands accepting a <em class="parameter"><code>textarget</code></em> parameter
            if <em class="parameter"><code>texture</code></em> is not zero, and
            <em class="parameter"><code>textarget</code></em> and the effective target of
            <em class="parameter"><code>texture</code></em> are not compatible.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            if <em class="parameter"><code>texture</code></em> is a buffer texture.
        </p>
      </div>
      <div class='refsect1' id='examples'><h2>Examples</h2><div class='example'>Create a framebuffer object with a texture-based color attachment and a texture-based depth attachment. Using texture-based attachments allows sampling of those textures in shaders.<pre class='programlisting'><span class='codecomment'>// fbo_width and fbo_height are the desired width and height of the FBO.</span>
<span class='codecomment'>// For Opengl &lt;= 4.4 or <span class='ckeyword'>if</span> the <span class='constant'>GL_ARB_</span>texture_non_power_of_two extension</span>
<span class='codecomment'>// is present, fbo_width and fbo_height can be values other than 2^n <span class='ckeyword'>for</span></span>
<span class='codecomment'>// some integer n.</span>

<span class='codecomment'>// Build the texture that will serve as the color attachment <span class='ckeyword'>for</span> the framebuffer.</span>
<span class='ckeyword'>GLuint</span> texture_map;
<a href='../gl4/glGenTextures'>glGenTextures</a>(1, &amp;texture_map);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, texture_map);

<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MIN_FILTER</span>, <span class='constant'>GL_LINEAR</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MAG_FILTER</span>, <span class='constant'>GL_LINEAR</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_S</span>, <span class='constant'>GL_CLAMP_TO_BORDER</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_T</span>, <span class='constant'>GL_CLAMP_TO_BORDER</span>);

<a href='../gl4/glTexImage2D'>glTexImage2D</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0, <span class='constant'>GL_RGBA</span>, fbo_width, fbo_height, 0, <span class='constant'>GL_RGBA</span>, <span class='constant'>GL_UNSIGNED_BYTE</span>, <span class='ckeyword'>NULL</span>);

<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0);

<span class='codecomment'>// Build the texture that will serve as the depth attachment <span class='ckeyword'>for</span> the framebuffer.</span>
<span class='ckeyword'>GLuint</span> depth_texture;
<a href='../gl4/glGenTextures'>glGenTextures</a>(1, &amp;depth_texture);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, depth_texture);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MIN_FILTER</span>, <span class='constant'>GL_NEAREST</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MAG_FILTER</span>, <span class='constant'>GL_NEAREST</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_S</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_T</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);
<a href='../gl4/glTexImage2D'>glTexImage2D</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0, <span class='constant'>GL_DEPTH_COMPONENT</span>, fbo_width, fbo_height, 0, <span class='constant'>GL_DEPTH_COMPONENT</span>, <span class='constant'>GL_UNSIGNED_BYTE</span>, <span class='ckeyword'>NULL</span>);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0);

<span class='codecomment'>// Build the framebuffer.</span>
<span class='ckeyword'>GLuint</span> framebuffer;
<a href='../gl4/glGenFramebuffers'>glGenFramebuffers</a>(1, &amp;framebuffer);
<a href='../gl4/glBindFramebuffer'>glBindFramebuffer</a>(<span class='constant'>GL_FRAMEBUFFER</span>, (<span class='ckeyword'>GLuint</span>)framebuffer);
<a href='../gl4/glFramebufferTexture'>glFramebufferTexture2D</a>(<span class='constant'>GL_FRAMEBUFFER</span>, <span class='constant'>GL_COLOR_ATTACHMENT0</span>, <span class='constant'>GL_TEXTURE_2D</span>, texture_map, 0);
<a href='../gl4/glFramebufferTexture'>glFramebufferTexture2D</a>(<span class='constant'>GL_FRAMEBUFFER</span>, <span class='constant'>GL_DEPTH_ATTACHMENT</span>, <span class='constant'>GL_TEXTURE_2D</span>, depth_texture, 0);

<span class='ckeyword'>GLenum</span> status = <a href='../gl4/glCheckFramebufferStatus'>glCheckFramebufferStatus</a>(<span class='constant'>GL_FRAMEBUFFER</span>);
<span class='ckeyword'>if</span> (status != <span class='constant'>GL_FRAMEBUFFER_COMPLETE</span>)
    <span class='codecomment'>// Error</span>

<a href='../gl4/glBindFramebuffer'>glBindFramebuffer</a>(<span class='constant'>GL_FRAMEBUFFER</span>, 0);</pre></div></div><div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://www.songho.ca/opengl/gl_fbo.html">Songho - OpenGL Frame Buffer Object (FBO)</a><br /><a href="https://open.gl/framebuffers">open.gl - Framebuffers</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-14-render-to-texture/">opengl-tutorial.org - Tutorial 14 : Render To Texture</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-16-shadow-mapping/">opengl-tutorial.org - Tutorial 16 : Shadow mapping</a><br /></p></div>
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
                  <code class="function">glFramebufferTexture</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glFramebufferTexture1D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glFramebufferTexture2D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glFramebufferTexture3D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
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
                  <code class="function">glNamedFramebufferTexture</code>
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
            <a class="citerefentry" href="glGenFramebuffers"><span class="citerefentry"><span class="refentrytitle">glGenFramebuffers</span></span></a>,
            <a class="citerefentry" href="glBindFramebuffer"><span class="citerefentry"><span class="refentrytitle">glBindFramebuffer</span></span></a>,
            <a class="citerefentry" href="glGenRenderbuffers"><span class="citerefentry"><span class="refentrytitle">glGenRenderbuffers</span></span></a>,
            <a class="citerefentry" href="glFramebufferTexture"><span class="citerefentry"><span class="refentrytitle">glFramebufferTexture</span></span></a>,
            <a class="citerefentry" href="glFramebufferTexture1D"><span class="citerefentry"><span class="refentrytitle">glFramebufferTexture1D</span></span></a>,
            <a class="citerefentry" href="glFramebufferTexture2D"><span class="citerefentry"><span class="refentrytitle">glFramebufferTexture2D</span></span></a>,
            <a class="citerefentry" href="glFramebufferTexture3D"><span class="citerefentry"><span class="refentrytitle">glFramebufferTexture3D</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glFramebufferTexture.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glFramebufferTexture glad_glFramebufferTexture
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glTexImage2DMultisample'>OpenGL 4</a><br /><a  href='../gl3/glTexImage2DMultisample'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glTexImage2DMultisample</h1>
    <div class="refentry" id="glTexImage2DMultisample">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glTexImage2DMultisample — establish the data storage, format, dimensions, and number of samples of a multisample texture's image</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTexImage2DMultisample</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">samples</var>, </td>
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
              <td>GLboolean <var class="pdparam">fixedsamplelocations</var><code>)</code>;</td>
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
                    Specifies the target of the operation. <em class="parameter"><code>target</code></em> must be <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code> or <code class="constant">GL_PROXY_TEXTURE_2D_MULTISAMPLE</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>samples</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    The number of samples in the multisample texture's image.
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
                    The internal format to be used to store the multisample texture's image. <em class="parameter"><code>internalformat</code></em> must specify a color-renderable, depth-renderable, or stencil-renderable format.
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
                    The width of the multisample texture's image, in texels.
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
                    The height of the multisample texture's image, in texels.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>fixedsamplelocations</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies whether the image will use identical sample locations and the same number of samples for all texels in the image, and the sample locations will not
                    depend on the internal format or size of the image.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glTexImage2DMultisample</code> establishes the data storage, format, dimensions and number of samples of a multisample texture's image.
        </p>
        <p>
            <em class="parameter"><code>target</code></em> must be
            <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code> or
            <code class="constant">GL_PROXY_TEXTURE_2D_MULTISAMPLE</code>.
            <em class="parameter"><code>width</code></em> and <em class="parameter"><code>height</code></em>
            are the dimensions in texels of the texture, and must be in the
            range zero to the value of
            <code class="constant">GL_MAX_TEXTURE_SIZE</code> minus one.
            <em class="parameter"><code>samples</code></em> specifies the number of samples
            in the image and must be in the range zero to the value of
            <code class="constant">GL_MAX_SAMPLES</code> minus one.
        </p>
        <p>
            <em class="parameter"><code>internalformat</code></em> must be a color-renderable, depth-renderable, or stencil-renderable format.
        </p>
        <p>
            If <em class="parameter"><code>fixedsamplelocations</code></em> is <code class="constant">GL_TRUE</code>, the image will use identical sample locations and the same
            number of samples for all texels in the image, and the sample locations will not depend on the internal format or size of the image.
        </p>
        <p>
            When a multisample texture is accessed in a shader, the access takes one vector of integers describing which texel to fetch and an integer
            corresponding to the sample numbers describing which sample within the texel to fetch. No standard sampling instructions are allowed on the
            multisample texture targets.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glTexImage2DMultisample</code> is available only if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>internalformat</code></em> is a depth- or stencil-renderable format and <em class="parameter"><code>samples</code></em>
            is greater than the value of <code class="constant">GL_MAX_DEPTH_TEXTURE_SAMPLES</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>internalformat</code></em> is a color-renderable format and <em class="parameter"><code>samples</code></em> is
            greater than the value of <code class="constant">GL_MAX_COLOR_TEXTURE_SAMPLES</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>internalformat</code></em> is a signed or unsigned integer format and <em class="parameter"><code>samples</code></em>
            is greater than the value of <code class="constant">GL_MAX_INTEGER_SAMPLES</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if either <em class="parameter"><code>width</code></em> or <em class="parameter"><code>height</code></em> negative or is greater than <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>samples</code></em> is greater than <code class="constant">GL_MAX_SAMPLES</code>.
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
                  <code class="function">glTexImage2DMultisample</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexImage2DMultisample"><span class="citerefentry"><span class="refentrytitle">glTexImage2DMultisample</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glTexImage2DMultisample.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glTexImage2DMultisample glad_glTexImage2DMultisample
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI PFNGLTEXIMAGE3DMULTISAMPLEPROC glad_glTexImage3DMultisample;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glTexImage3DMultisample'>OpenGL 4</a><br /><a  href='../gl3/glTexImage3DMultisample'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glTexImage3DMultisample</h1>
    <div class="refentry" id="glTexImage3DMultisample">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glTexImage3DMultisample — establish the data storage, format, dimensions, and number of samples of a multisample texture's image</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTexImage3DMultisample</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">samples</var>, </td>
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
              <td>GLboolean <var class="pdparam">fixedsamplelocations</var><code>)</code>;</td>
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
                    Specifies the target of the operation. <em class="parameter"><code>target</code></em> must be <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code> or <code class="constant">GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>samples</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    The number of samples in the multisample texture's image.
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
                    The internal format to be used to store the multisample texture's image. <em class="parameter"><code>internalformat</code></em> must specify a color-renderable, depth-renderable, or stencil-renderable format.
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
                    The width of the multisample texture's image, in texels.
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
                    The height of the multisample texture's image, in texels.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>fixedsamplelocations</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies whether the image will use identical sample locations and the same number of samples for all texels in the image, and the sample locations will not
                    depend on the internal format or size of the image.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glTexImage3DMultisample</code> establishes the data storage, format, dimensions and number of samples of a multisample texture's image.
        </p>
        <p>
            <em class="parameter"><code>target</code></em> must be
            <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code> or
            <code class="constant">GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY</code>.
            <em class="parameter"><code>width</code></em> and
            <em class="parameter"><code>height</code></em>are the dimensions in texels of the
            texture, and must be in the range zero to the value of
            <code class="constant">GL_MAX_TEXTURE_SIZE</code> minus one.
            <em class="parameter"><code>depth</code></em> is the number of array slices in
            the array texture's image. <em class="parameter"><code>samples</code></em>
            specifies the number of samples in the image and must be in the
            range zero to the value of <code class="constant">GL_MAX_SAMPLES</code>
            minus one.
        </p>
        <p>
            <em class="parameter"><code>internalformat</code></em> must be a color-renderable, depth-renderable, or stencil-renderable format.
        </p>
        <p>
            If <em class="parameter"><code>fixedsamplelocations</code></em> is <code class="constant">GL_TRUE</code>, the image will use identical sample locations and the same
            number of samples for all texels in the image, and the sample locations will not depend on the internal format or size of the image.
        </p>
        <p>
            When a multisample texture is accessed in a shader, the access takes one vector of integers describing which texel to fetch and an integer
            corresponding to the sample numbers describing which sample within the texel to fetch. No standard sampling instructions are allowed on the
            multisample texture targets.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glTexImage2DMultisample</code> is available only if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>internalformat</code></em> is a depth- or stencil-renderable format and <em class="parameter"><code>samples</code></em>
            is greater than the value of <code class="constant">GL_MAX_DEPTH_TEXTURE_SAMPLES</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>internalformat</code></em> is a color-renderable format and <em class="parameter"><code>samples</code></em> is
            greater than the value of <code class="constant">GL_MAX_COLOR_TEXTURE_SAMPLES</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>internalformat</code></em> is a signed or unsigned integer format and <em class="parameter"><code>samples</code></em>
            is greater than the value of <code class="constant">GL_MAX_INTEGER_SAMPLES</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if either <em class="parameter"><code>width</code></em> or <em class="parameter"><code>height</code></em> negative or is greater than <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>depth</code></em> is negative or is greater than <code class="constant">GL_MAX_ARRAY_TEXTURE_LAYERS</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>samples</code></em> is greater than <code class="constant">GL_MAX_SAMPLES</code>.
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
                  <code class="function">glTexImage3DMultisample</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexImage2DMultisample"><span class="citerefentry"><span class="refentrytitle">glTexImage2DMultisample</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glTexImage3DMultisample.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glTexImage3DMultisample glad_glTexImage3DMultisample
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat *val);
GLAPI PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetMultisample'>OpenGL 4</a><br /><a  href='../gl3/glGetMultisample'>OpenGL 3</a><br /></div>
      <h1 id="command_title">glGetMultisample</h1>
    <div class="refentry" id="glGetMultisample">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetMultisamplefv — retrieve the location of a sample</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetMultisamplefv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat *<var class="pdparam">val</var><code>)</code>;</td>
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
                    Specifies the sample parameter name. <em class="parameter"><code>pname</code></em> must be <code class="constant">GL_SAMPLE_POSITION</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>index</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the index of the sample whose position to query.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>val</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of an array to receive the position of the sample.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetMultisamplefv</code> queries the location of
            a given sample. <em class="parameter"><code>pname</code></em> specifies the
            sample parameter to retrieve and must be
            <code class="constant">GL_SAMPLE_POSITION</code>.
            <em class="parameter"><code>index</code></em> corresponds to the sample for which
            the location should be returned. The sample location is returned
            as two floating-point values in <em class="parameter"><code>val[0]</code></em>
            and <em class="parameter"><code>val[1]</code></em>, each between 0 and 1,
            corresponding to the <em class="parameter"><code>x</code></em> and
            <em class="parameter"><code>y</code></em> locations respectively in the GL pixel
            space of that sample. (0.5, 0.5) this corresponds to the pixel
            center. <em class="parameter"><code>index</code></em> must be between zero and
            the value of <code class="constant">GL_SAMPLES</code> minus one.
        </p>
        <p>
            If the multisample mode does not have fixed sample locations, the returned values may only reflect the locations of samples
            within some pixels.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>pname</code></em> is not one <code class="constant">GL_SAMPLE_POSITION</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>index</code></em> is greater than or equal to the value of
            <code class="constant">GL_SAMPLES</code>.
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
                  <code class="function">glGetMultisamplefv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glGenFramebuffers"><span class="citerefentry"><span class="refentrytitle">glGenFramebuffers</span></span></a>,
            <a class="citerefentry" href="glBindFramebuffer"><span class="citerefentry"><span class="refentrytitle">glBindFramebuffer</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetMultisample.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glGetMultisamplefv glad_glGetMultisamplefv
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
GLAPI PFNGLSAMPLEMASKIPROC glad_glSampleMaski;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glSampleMaski'>OpenGL 4</a><br /><a  href='../gl3/glSampleMaski'>OpenGL 3</a><br /><a  href='../es3/glSampleMaski'>OpenGL ES 3</a><br /></div>
      <h1 id="command_title">glSampleMaski</h1>
    <div class="refentry" id="glSampleMaski">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glSampleMaski — set the value of a sub-word of the sample mask</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glSampleMaski</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">maskNumber</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLbitfield <var class="pdparam">mask</var><code>)</code>;</td>
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
                  <code>maskNumber</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies which 32-bit sub-word of the sample mask to update.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>mask</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the new value of the mask sub-word.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glSampleMaski</code> sets one 32-bit sub-word of the multi-word sample mask, <code class="constant">GL_SAMPLE_MASK_VALUE</code>.
        </p>
        <p>
            <em class="parameter"><code>maskIndex</code></em> specifies which 32-bit sub-word of the sample mask to update, and <em class="parameter"><code>mask</code></em> specifies
            the new value to use for that sub-word. <em class="parameter"><code>maskIndex</code></em> must be less than the value of
            <code class="constant">GL_MAX_SAMPLE_MASK_WORDS</code>. Bit <span class="emphasis"><em>B</em></span> of mask word <span class="emphasis"><em>M</em></span> corresponds to sample
            32 x <span class="emphasis"><em>M</em></span> + <span class="emphasis"><em>B</em></span>.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glSampleMaski</code> is available only if the GL version is 3.2 or greater, or if the <code class="code">ARB_texture_multisample</code>
            extension is supported.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_SAMPLE_MASK_VALUE</code>
        </p>
			</div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>maskIndex</code></em> is greater than or equal to the value
            of <code class="constant">GL_MAX_SAMPLE_MASK_WORDS</code>.
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
                  <code class="function">glSampleMaski</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
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
            <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2010-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glSampleMaski.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glSampleMaski glad_glSampleMaski
#endif
#endif