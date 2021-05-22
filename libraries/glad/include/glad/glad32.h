#ifndef GL_VERSION_4_6
#define GL_VERSION_4_6 1
GLAPI int GLAD_GL_VERSION_4_6;
typedef void (APIENTRYP PFNGLSPECIALIZESHADERPROC)(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
GLAPI PFNGLSPECIALIZESHADERPROC glad_glSpecializeShader;
#define glSpecializeShader glad_glSpecializeShader
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glad_glMultiDrawArraysIndirectCount;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glMultiDrawArraysIndirect'>OpenGL 4</a><br /></div>
      <h1 id="command_title">glMultiDrawArraysIndirect</h1>
    <div class="refentry" id="glMultiDrawArraysIndirect">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glMultiDrawArraysIndirect — render multiple sets of primitives from array data, taking parameters from memory</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glMultiDrawArraysIndirect</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const void *<var class="pdparam">indirect</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">drawcount</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">stride</var><code>)</code>;</td>
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
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code>, and
                    <code class="constant">GL_PATCHES</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>indirect</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of an array of structures containing the draw parameters.
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
                    Specifies the the number of elements in the array of draw parameter structures.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>stride</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the distance in basic machine units between elements of the draw parameter array.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glMultiDrawArraysIndirect</code> specifies multiple geometric primitives
            with very few subroutine calls. <code class="function">glMultiDrawArraysIndirect</code> behaves
            similarly to a multitude of calls to <a class="citerefentry" href="glDrawArraysInstancedBaseInstance"><span class="citerefentry"><span class="refentrytitle">glDrawArraysInstancedBaseInstance</span></span></a>,
            execept that the parameters to each call to <a class="citerefentry" href="glDrawArraysInstancedBaseInstance"><span class="citerefentry"><span class="refentrytitle">glDrawArraysInstancedBaseInstance</span></span></a>
            are stored in an array in memory at the address given by <em class="parameter"><code>indirect</code></em>, separated
            by the stride, in basic machine units, specified by <em class="parameter"><code>stride</code></em>. If <em class="parameter"><code>stride</code></em>
            is zero, then the array is assumed to be tightly packed in memory.
        </p>
        <p>
            The parameters addressed by <em class="parameter"><code>indirect</code></em> are packed into an array of structures,
            each element of which takes the form (in C):
            </p>
        <pre class="programlisting">    typedef  struct {
        uint  count;
        uint  instanceCount;
        uint  first;
        uint  baseInstance;
    } DrawArraysIndirectCommand;</pre>
        <p>
        </p>
        <p>
            A single call to <code class="function">glMultiDrawArraysIndirect</code> is equivalent, assuming no errors
            are generated to:
            </p>
        <pre class="programlisting">    GLsizei n;
    for (n = 0; n &lt; drawcount; n++) {
        const DrawArraysIndirectCommand *cmd;
        if (stride != 0) {
            cmd = (const DrawArraysIndirectCommand  *)((uintptr)indirect + n * stride);
        } else  {
            cmd = (const DrawArraysIndirectCommand  *)indirect + n;
        }

        glDrawArraysInstancedBaseInstance(mode, cmd-&gt;first, cmd-&gt;count, cmd-&gt;instanceCount, cmd-&gt;baseInstance);
    }</pre>
        <p>
        </p>
        <p>
            If a buffer is bound to the <code class="constant">GL_DRAW_INDIRECT_BUFFER</code> binding at the time
            of a call to <code class="function">glMultiDrawArraysIndirect</code>, <em class="parameter"><code>indirect</code></em>
            is interpreted as an offset, in basic machine units, into that buffer and the parameter
            data is read from the buffer rather than from client memory.
        </p>
        <p>
            In contrast to <a class="citerefentry" href="glDrawArraysInstancedBaseInstance"><span class="citerefentry"><span class="refentrytitle">glDrawArraysInstancedBaseInstance</span></span></a>,
            the <code class="code">first</code> member of the parameter structure is unsigned, and out-of-range indices
            do not generate an error.
        </p>
        <p>
            Vertex attributes that are modified by <code class="function">glMultiDrawArraysIndirect</code> have an
            unspecified value after <code class="function">glMultiDrawArraysIndirect</code> returns. Attributes that aren't
            modified remain well defined.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The <em class="parameter"><code>baseInstance</code></em> member of the <em class="parameter"><code>DrawArraysIndirectCommand</code></em>
            structure is defined only if the GL version is 4.2 or greater. For versions of the GL less than 4.2,
            this parameter is present but is reserved and should be set to zero. On earlier versions of the GL,
            behavior is undefined if it is non-zero.
        </p>
        <p>
            <code class="function">glMultiDrawArraysIndirect</code> is available only if the GL version is 4.3 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>stride</code></em> is not a multiple
            of four.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>drawcount</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to an
            enabled array or to the <code class="constant">GL_DRAW_INDIRECT_BUFFER</code> binding and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a geometry shader is active and <em class="parameter"><code>mode</code></em>
            is incompatible with the input primitive type of the geometry shader in the currently installed program object.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>mode</code></em> is <code class="constant">GL_PATCHES</code>
            and no tessellation control shader is active.
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
                  <code class="function">glMultiDrawArraysIndirect</code>
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
            <a class="citerefentry" href="glDrawArraysInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawArraysInstanced</span></span></a>,
            <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>,
            <a class="citerefentry" href="glDrawArraysIndirect"><span class="citerefentry"><span class="refentrytitle">glDrawArraysIndirect</span></span></a>,
            <a class="citerefentry" href="glMultiDrawElementsIndirect"><span class="citerefentry"><span class="refentrytitle">glMultiDrawElementsIndirect</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2012-2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glMultiDrawArraysIndirect.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glMultiDrawArraysIndirectCount glad_glMultiDrawArraysIndirectCount
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glad_glMultiDrawElementsIndirectCount;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glMultiDrawElementsIndirect'>OpenGL 4</a><br /></div>
      <h1 id="command_title">glMultiDrawElementsIndirect</h1>
    <div class="refentry" id="glMultiDrawElementsIndirect">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glMultiDrawElementsIndirect — render indexed primitives from array data, taking parameters from memory</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glMultiDrawElementsIndirect</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const void *<var class="pdparam">indirect</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">drawcount</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">stride</var><code>)</code>;</td>
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
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code>, and
                    <code class="constant">GL_PATCHES</code>
                    are accepted.
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
                    Specifies the type of data in the buffer bound to the <code class="constant">GL_ELEMENT_ARRAY_BUFFER</code> binding.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>indirect</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the address of a structure containing an array of draw parameters.
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
                    Specifies the number of elements in the array addressed by <em class="parameter"><code>indirect</code></em>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>stride</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the distance in basic machine units between elements of the draw parameter array.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glMultiDrawElementsIndirect</code> specifies multiple indexed geometric primitives
            with very few subroutine calls. <code class="function">glMultiDrawElementsIndirect</code> behaves
            similarly to a multitude of calls to <a class="citerefentry" href="glDrawElementsInstancedBaseVertexBaseInstance"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstancedBaseVertexBaseInstance</span></span></a>,
            execpt that the parameters to <a class="citerefentry" href="glDrawElementsInstancedBaseVertexBaseInstance"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstancedBaseVertexBaseInstance</span></span></a>
            are stored in an array in memory at the address given by <em class="parameter"><code>indirect</code></em>, separated
            by the stride, in basic machine units, specified by <em class="parameter"><code>stride</code></em>. If <em class="parameter"><code>stride</code></em>
            is zero, then the array is assumed to be tightly packed in memory.
        </p>
        <p>
            The parameters addressed by <em class="parameter"><code>indirect</code></em> are packed into a structure
            that takes the form (in C):
            </p>
        <pre class="programlisting">    typedef  struct {
        uint  count;
        uint  instanceCount;
        uint  firstIndex;
        uint  baseVertex;
        uint  baseInstance;
    } DrawElementsIndirectCommand;</pre>
        <p>
        </p>
        <p>
            A single call to <code class="function">glMultiDrawElementsIndirect</code> is equivalent, assuming no errors
            are generated to:
            </p>
        <pre class="programlisting">    GLsizei n;
    for (n = 0; n &lt; drawcount; n++) {
        const DrawElementsIndirectCommand *cmd;
        if (stride != 0) {
            cmd = (const DrawElementsIndirectCommand  *)((uintptr)indirect + n * stride);
        } else {
            cmd = (const DrawElementsIndirectCommand  *)indirect + n;
        }

        glDrawElementsInstancedBaseVertexBaseInstance(mode,
                                                      cmd-&gt;count,
                                                      type,
                                                      cmd-&gt;firstIndex * size-of-type,
                                                      cmd-&gt;instanceCount,
                                                      cmd-&gt;baseVertex,
                                                      cmd-&gt;baseInstance);
    }</pre>
        <p>
        </p>
        <p>
            If a buffer is bound to the <code class="constant">GL_DRAW_INDIRECT_BUFFER</code> binding at the time
            of a call to <code class="function">glDrawElementsIndirect</code>, <em class="parameter"><code>indirect</code></em>
            is interpreted as an offset, in basic machine units, into that buffer and the parameter
            data is read from the buffer rather than from client memory.
        </p>
        <p>
            Note that indices stored in client memory are not supported. If no buffer is bound to the
            <code class="constant">GL_ELEMENT_ARRAY_BUFFER</code> binding, an error will be generated.
        </p>
        <p>
            The results of the operation are undefined if the <code class="code">reservedMustBeZero</code> member
            of the parameter structure is non-zero. However, no error is generated in this case.
        </p>
        <p>
            Vertex attributes that are modified by <code class="function">glDrawElementsIndirect</code> have an
            unspecified value after <code class="function">glDrawElementsIndirect</code> returns. Attributes that aren't
            modified remain well defined.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The <em class="parameter"><code>baseInstance</code></em> member of the <em class="parameter"><code>DrawElementsIndirectCommand</code></em>
            structure is defined only if the GL version is 4.2 or greater. For versions of the GL less than 4.2,
            this parameter is present but is reserved and should be set to zero. On earlier versions of the GL,
            behavior is undefined if it is non-zero.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>stride</code></em> is not a multiple
            of four.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>drawcount</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if no buffer is bound to the <code class="constant">GL_ELEMENT_ARRAY_BUFFER</code>
            binding, or if such a buffer's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to an
            enabled array or to the <code class="constant">GL_DRAW_INDIRECT_BUFFER</code> binding and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a geometry shader is active and <em class="parameter"><code>mode</code></em>
            is incompatible with the input primitive type of the geometry shader in the currently installed program object.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>mode</code></em> is <code class="constant">GL_PATCHES</code>
            and no tessellation control shader is active.
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
                  <code class="function">glMultiDrawElementsIndirect</code>
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
            <a class="citerefentry" href="glDrawArraysInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawArraysInstanced</span></span></a>,
            <a class="citerefentry" href="glDrawArraysIndirect"><span class="citerefentry"><span class="refentrytitle">glDrawArraysIndirect</span></span></a>,
            <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>,
            <a class="citerefentry" href="glDrawElementsIndirect"><span class="citerefentry"><span class="refentrytitle">glDrawElementsIndirect</span></span></a>,
            <a class="citerefentry" href="glMultiDrawArraysIndirect"><span class="citerefentry"><span class="refentrytitle">glMultiDrawArraysIndirect</span></span></a>
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glMultiDrawElementsIndirect.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glMultiDrawElementsIndirectCount glad_glMultiDrawElementsIndirectCount
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
GLAPI PFNGLPOLYGONOFFSETCLAMPPROC glad_glPolygonOffsetClamp;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glPolygonOffset'>OpenGL 4</a><br /><a  href='../gl3/glPolygonOffset'>OpenGL 3</a><br /><a  href='../gl2/glPolygonOffset'>OpenGL 2</a><br /><a  href='../es3/glPolygonOffset'>OpenGL ES 3</a><br /><a  href='../es2/glPolygonOffset'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glPolygonOffset</h1>
    <div class="refentry" id="glPolygonOffset">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glPolygonOffset — set the scale and units used to calculate depth values</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPolygonOffset</strong>(</code>
              </td>
              <td>GLfloat <var class="pdparam">factor</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">units</var><code>)</code>;</td>
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
                  <code>factor</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a scale factor that is used to create a variable
                    depth offset for each polygon. The initial value is 0.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>units</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Is multiplied by an implementation-specific value to
                    create a constant depth offset. The initial value is 0.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            When <code class="constant">GL_POLYGON_OFFSET_FILL</code>, <code class="constant">GL_POLYGON_OFFSET_LINE</code>, or
            <code class="constant">GL_POLYGON_OFFSET_POINT</code> is enabled, each
            fragment's <span class="emphasis"><em>depth</em></span> value will be offset after it is interpolated
            from the <span class="emphasis"><em>depth</em></span> values of the appropriate vertices.
            The value of the offset is
            <math overflow="scroll">

                <mrow>
                    <mrow>
                        <mi mathvariant="italic">factor</mi>
                        <mo>×</mo>
                        <mi mathvariant="italic">DZ</mi>
                    </mrow>
                    <mo>+</mo>
                    <mrow>
                        <mi mathvariant="italic">r</mi>
                        <mo>×</mo>
                        <mi mathvariant="italic">units</mi>
                    </mrow>
                </mrow>
            </math>,
            where
            <math overflow="scroll">

                <mi mathvariant="italic">DZ</mi>
            </math>
            is a measurement of the change in depth relative to the screen
            area of the polygon, and
            <math overflow="scroll"><mi mathvariant="italic">r</mi></math>
            is the smallest value that is guaranteed to
            produce a resolvable offset for a given implementation.
            The offset is added before the depth test is performed and before
            the value is written into the depth buffer.
        </p>
        <p>
            <code class="function">glPolygonOffset</code> is useful for rendering hidden-line images, for applying decals
            to surfaces, and for rendering solids with highlighted edges.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a> with argument
            <code class="constant">GL_POLYGON_OFFSET_FILL</code>,
            <code class="constant">GL_POLYGON_OFFSET_LINE</code>,
            or <code class="constant">GL_POLYGON_OFFSET_POINT</code>.
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POLYGON_OFFSET_FACTOR</code> or
            <code class="constant">GL_POLYGON_OFFSET_UNITS</code>.
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
                  <code class="function">glPolygonOffset</code>
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
            <a class="citerefentry" href="glDepthFunc"><span class="citerefentry"><span class="refentrytitle">glDepthFunc</span></span></a>,
            <a class="citerefentry" href="glEnable"><span class="citerefentry"><span class="refentrytitle">glEnable</span></span></a>,
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>,
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>
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

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glPolygonOffset.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
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

#define glPolygonOffsetClamp glad_glPolygonOffsetClamp
#endif

#ifdef __cplusplus
}
#endif

